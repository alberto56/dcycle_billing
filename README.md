Dcycle Billing
==============

A simple billing solution using Drupal and developing using the
[Dcycle method](http://dcycleproject.org/).

Dependencies
-----

 * Docker

Upgrading from previous non-docker installation
-----

    drush cc all && drush sql-dump > ~/Desktop/sql.sql
    git pull origin master
    chmod -R +w sites/default
    mv sites/default/settings.php ~/Desktop/settings.php-backup-delete-if-all-goes-well
    ./dcycle-billing/create.sh
    docker cp ~/Desktop/sql.sql "$(docker-compose ps -q web)":/my-database.sql
    docker-compose exec web /bin/bash -c "drush sqlc < /my-database.sql"
    ./dcycle-billing/create.sh

(Running create.sh a second time takes care of running the update scripts.)

Installation and update
------------

Whether you are installing or updating the project, run:

    ./dcycle-billing/create.sh

Features
--------

Defining new customers should be done while you create an order:

 * Log in with an administrator account.
 * Go to admin/commerce/orders/add
 * In "Create a new customer", enter your customer's email address
 * Create your order.
 * For orders set to "invoiced", you can download a PDF invoice.
