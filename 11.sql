SELECT title 
FROM movies
WHERE id IN (
    SELECT ratings.movie_id 
    FROM ratings 
        JOIN stars ON ratings.movie_id = stars.movie_id 
        WHERE stars.person_id = (
        select id from people where name = "Chadwick Boseman")
    ORDER BY ratings.rating DESC LIMIT 5);
