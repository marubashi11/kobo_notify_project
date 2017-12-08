#!/bin/sh

sleep(10)
curl -X POST -H 'Authorization: Bearer *************************' -F 'message=MONOTSUKURI studio has been opened.' https://notify-api.line.me 
sudo shutdown -h now
