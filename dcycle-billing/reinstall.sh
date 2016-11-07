#!/bin/bash

docker-compose exec web /bin/bash -c 'drush pmu -y drupal8tests'
docker-compose exec web /bin/bash -c 'drush en -y drupal8tests'
