#!/bin/bash

docker-compose exec web /bin/bash -c 'drush sqlc'
