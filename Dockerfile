FROM drupal:7

RUN curl -sS https://getcomposer.org/installer | php
RUN mv composer.phar /usr/local/bin/composer
RUN composer global require drush/drush:8
RUN ln -s /root/.composer/vendor/drush/drush/drush /bin/drush

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y mysql-client

ADD docker-resources/run.sh /run.sh

# See https://www.drupal.org/node/1826652
RUN echo 'sendmail_path = /bin/true' >> /usr/local/etc/php/php.ini

RUN drush dl registry_rebuild

EXPOSE 80
