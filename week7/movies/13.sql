SELECT DISTINCT people.name FROM people
INNER JOIN stars ON people.id = stars.person_id
INNER JOIN movies ON stars.movie_id = movies.id
INNER JOIN stars AS kevin ON movies.id = kevin.movie_id
INNER JOIN people AS kevin_person ON kevin.person_id = kevin_person.id
WHERE kevin_person.name = 'Kevin Bacon'
AND kevin_person.birth = 1958 AND people.name != 'Kevin Bacon';