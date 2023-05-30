-- Keep a log of any SQL queries you execute as you solve the mystery.
-- First of first i need to find any information
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humpherey Street';

SELECT id, activity FROM bakery_security_logs
WHERE month = 7 AND day = 28;
WHERE month = 7 AND day = 28;