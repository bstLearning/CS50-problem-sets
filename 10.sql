SELECT name FROM people
WHERE id IN (
SELECT directors.person_id FROM 
directors JOIN  movies ON directors.movie_id = movies.id
JOIN ratings on directors.movie_id = ratings.movie_id
JOIN people on directors.person_id = people.id
WHERE ratings.rating >= 9.0);