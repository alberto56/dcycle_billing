#!/bin/bash

docker-compose exec web /bin/bash -c \
  "drush -l http://$(docker-compose port web 80) uli"
