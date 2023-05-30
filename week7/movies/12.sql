SELECT title FROM movies WHERE id IN(SELECT movie_id FROM stars
INNER JOIN people ON stars.person_id = people.id
WHERE people.name = 'Johnny Depp')
AND id IN(SELECT movie_id FROM stars
INNER JOIN people ON stars.person_id = people.id
WHERE people.name = 'Helena Bonham Carter');