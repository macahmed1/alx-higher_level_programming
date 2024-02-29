#!/bin/bash
# Bash scripts that sends a POST request to a given URL.
curl -s -X POST -d "email=hr@school.com&subject=I will always be here for PLD" "$1"
