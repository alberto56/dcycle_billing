This module allows developers to cache tables in their tests' setUp() function, meaning tests run faster if many test cases use the same setUp(), and that setUp() function Simpletest Turbo-aware.

Making your setUp() function Simpletest Turbo-aware
---------------------------------------------------

To see the difference between a standard setUp() function and a Simpletest Turbo-aware setUp() function, see the classes in `simpletest_turbo.test`.

Which test architecture can benefit the most from this module
-------------------------------------------------------------

It is considered good practice to have many short tests, each independent of the others. A typical test architecture for Drupal modules will consist of:

 * A base test class containing a setUp() function but no actual tests.
 * Subclasses which extend the custom base test class, each containing one or more test functions. Each test function, when it is run, requires setUp() to be run before it.
 * The more tests you have, the bigger the speed increase.
 * The longer it takes for your setUp() function to install your test site, the bigger the speed increase. Particularly, if you are using a [site deployment module](http://dcycleproject.org/blog/44/) to install your entire site, it can take several minutes, especially if you are importing translations and have complex features.

Drupal 8
--------

Please see and comment on [this issue](https://www.drupal.org/node/2283553).

To see how it works
-------------------

(1) Enable this module:

    drush en simpletest_turbo -y

(2) Make sure that in your sites/default/settings.php, you set the $base_url variable properly. This will allow the test, when run on the command line, to actually make cUrl requests to your site using the temporary test database.

(3) On the command line, run the optimized and not optimized test.

    drush turbo-reset
    drush test-run simpletest_turbo_optimized

    drush test-run simpletest_turbo_not_optimized

Some extra code on the command line will allow you to see how many seconds each test run takes:

    drush turbo-reset
    START=$(date +%s)\
    && drush test-run simpletest_turbo_optimized\
    && echo "Tests completed in $(echo "$(date +%s) - $START"|bc) seconds"

    START=$(date +%s)\
    && drush test-run simpletest_turbo_not_optimized\
    && echo "Tests completed in $(echo "$(date +%s) - $START"|bc) seconds"

In the above example, on my machine tests take less than half as long, one third as long in certain cases.

OPTIMIZING YOUR TESTS
---------------------

You need to change the setUp() functions of your tests. Please see the enclosed test class code to understand the changes which need to be made. Once your setUp() code is modified, Simpletest Turbo will copy all your test temporary tables to its own temporary tables. Further calls to setUp() will check for Simpletest Turbo's temporary tables, and if they exist, will copy them instead of re-installing Drupal.

NOTES
-----

 * This module has only been tested on the command line, not the GUI.

 * This module has only been tested with MySQL, not SQLite.

 * For complex tests I needed to increase my PHP memory to 1024 to avoid memory problems.

 * Never use table prefixes on your test host (with or without Simpletest Turbo), because your table names will become too long for MySQL.

This module is sponsored by [CGI](http://cgi.com).
