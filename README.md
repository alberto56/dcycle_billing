Dcycle Billing
==============

A simple billing solution using Drupal and developing using the [Dcycle method](http://dcycleproject.org/).

Installation
------------

Our first release should do the following:

    echo 'create database mydatabase' | mysql -uroot -proot
    drush si --db-url=mysql://root:root@localhost/mydatabase
    drush en manage_deploy -y
    drush uli

Update
------

    drush vset maintenance_mode 1
    git pull origin master
    drush dl registry_rebuild
    drush rr
    drush cc all
    drush updb -y
    drush vset maintenance_mode 0

Features
--------

To define new clients:

 * Log in with an administrator account.


The following features are included in this sytem:

 * Allow admins to define clients
 * Each client should have a preferred currency
 * Each client should have a rate
 * Each client should have an address
 * Allow consultants to add time tracking: a number of hours for a given client.

Our first release should do the following:

 * Allow admins to create new invoices, and optionally import all tracked time for the associated client.
 * New invoices for a given client will import all time tracked for that client.
 * Invoiced time is marked as invoiced and one can see the associated invoice.
 * When time tracked is invoiced, it can no longer be modified.
 * Allow admins to add payments manually.
 
 * Allow timetracking: entering a number of hours