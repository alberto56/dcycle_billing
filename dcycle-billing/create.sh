#!/bin/bash
set -e

./dcycle-billing/destroy.sh
docker-compose build
docker-compose up -d
docker-compose exec web /run.sh

mkdir -p ./database/mysql

echo ''
echo 'If all went well you can now access your site at:'
echo ''
echo ' => '$(./dcycle-billing/uli.sh)
echo ''
