#!/bin/bash

docker-compose exec web /bin/bash -c 'drush ws --count=1 --extended'
