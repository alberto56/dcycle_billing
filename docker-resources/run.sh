#!/bin/bash
set -e

echo 'Because we are sharing the database at ./database/mysql, we can'
echo 'whether the site has already been installed by checking whether'
echo '/var/www/html/database/mysql/auto.cnf exists on the container.'
if [ ! -f /var/www/html/database/mysql/auto.cnf ]; then
  echo 'Because it does not, we can determine that the site has not yet'
  echo 'been installed, so we will install it.'

  cd /var/www/html && \
    drush si \
    -y --db-url=mysql://drupal:drupal@database:3306/drupal

  # If we do not enable inline_entity_form, it does not get enabled as a
  # dependency of manage_deploy, not sure why.
  cd /var/www/html && \
    drush en inline_entity_form -y && \
    drush en manage_deploy -y && \
    chown -R www-data:www-data ./sites/default/files && \
    drush cc all
else
  echo 'Because it exists, we will simply update the existing site.'
  echo 'First let us wait 15 seconds for the MySQL server to fire up.'
  sleep 15
  cd /var/www/html && \
    drush vset maintenance_mode 1 && \
    drush rr && \
    drush cc all && \
    drush updb -y && \
    drush vset maintenance_mode 0
fi
