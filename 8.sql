SELECT people.name
FROM stars 
    JOIN movies ON stars.movie_id = movies.id, 
    people ON stars.person_id = people.id
WHERE movies.title = "Toy Story";