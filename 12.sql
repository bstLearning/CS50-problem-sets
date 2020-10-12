SELECT title
FROM movies 
WHERE movies.id IN(
	SELECT movie_id 
	FROM people 
		JOIN stars ON people.id = stars.person_id
	WHERE people.id = (
		SELECT id 
		FROM people 
		WHERE name = "Johnny Depp"))
AND movies.id IN(
	SELECT movie_id 
	FROM people
		JOIN stars ON people.id = stars.person_id
	WHERE people.id = (
		SELECT id 
		FROM people
		WHERE people.name = "Helena Bonham Carter"));