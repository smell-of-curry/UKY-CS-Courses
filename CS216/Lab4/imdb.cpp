/*
 * File: imdb.cpp
 * Course: CS216-00x
 * Project: Project 1
 * Purpose: Provide the implementation of the class named IMDB
 *          This class represents a movie-actor database
 */
#include <regex>  // needs c++11 standard
#include "imdb.h"

using namespace std;

// default constructor
IMDB::IMDB()
{
    //do nothing
    //since map class contains a default contructor
    //      which constructs an empty container, with no elements
}

// insert a pair <movieTitle, the set of actor names in this movie>
// this function is optional to this project
// pratice during the Lecture for your reference
void IMDB::insert_a_movie(string movieTitle, set<string> actorNames) 
{
    // First upgrade movies_db
    // if the key moiveTitle does not exist in movies_db
    //        add the key to the map movies_db
    if (!isExistingMovie(movieTitle))
        movies_db[movieTitle] = actorNames;
    else // if the key movieTitle is an existing key in movies_db
    {
        movies_db[movieTitle].insert(actorNames.begin(), actorNames.end());
    }

    // Second upgrade actors_db
    // for each actor name in the set of actorNames,
    // insert movieTitle to its movie set
    for (auto it = actorNames.begin(); it != actorNames.end(); it++)
    {
        // if *it is not an existing key in actors_db
        if (actors_db.find(*it) == actors_db.end())
        {
            set<string> movies;
            movies.insert(movieTitle);
            actors_db[*it] = movies;
        }
        else // if *it is an existing key in actors_db
        {
            actors_db[*it].insert(movieTitle);
        }
    }
}

// insert a pair<actorName, the set of movieTitle of this actor>
void IMDB::insert_an_actor(string actorName, set<string> movieTitles)
{
    // First upgrade actors_db
    // if the key actorName does not exist in actors_db
    //        add the key to the map actors_db

    if (!isExistingActor(actorName))
        actors_db[actorName] = movieTitles;
    else // if the key actorName is an existing key in actors_db
    {
        actors_db[actorName].insert(movieTitles.begin(), movieTitles.end());
    }

    // Second upgrade movies_db
    // for each movieTitle in the set of movieTitles,
    // insert actorName to its actors set

    for (auto it = movieTitles.begin(); it != movieTitles.end(); it++)
    {
        // if *it is not an existing key in movies_db
        if (movies_db.find(*it) == movies_db.end())
        {
            set<string> actors;
            actors.insert(actorName);
            movies_db[*it] = actors;
        }
        else // if *it is an existing key in movies_db
        {
            movies_db[*it].insert(actorName);
        }
    }
}

// use passing in parameter, movieTitle, as the pattern to match 
// one existing movie in the map
// return the matched movie title from the map
// otherwise return empty string
string IMDB::matchExistingMovie(string movieTitle) const
{
    string matchedMovie;
    bool found = false;
    // generate the regular expression to match 
    // which contains movieTitle as a substring
    // note that it performs case insensitive matching
    regex reg(movieTitle, regex_constants::icase);
    auto it = movies_db.begin();
    while (!found && it != movies_db.end())
    {
        if (regex_search(it->first, reg))
        {
            found = true;
            matchedMovie = it->first;
        }
        else
            it++;
    }
    return matchedMovie;
}

// check if a movieTitle does exist in the map
// return true if it does; otherwise return false
bool IMDB::isExistingMovie(string movieTitle) const
{
	return movies_db.find(movieTitle) != movies_db.end();
}

// check if an actorName does exist in the map
// return true if it does; otherwise return false
bool IMDB::isExistingActor(string actorName) const
{
	return actors_db.find(actorName) != actors_db.end();
}

// Return a set of movie titles which actorName is in
// If the passing in parameter: actorName, is not in the database,
// display message and return an empty set
set<string> IMDB::find_movies_for_an_actor(string actorName) const
{
    auto it = actors_db.find(actorName); // Correctly use actors_db
    if (it != actors_db.end()) {
        return it->second; // Access the set of movies
    }

    cout << "Actor: " << actorName << " is not in the database" << endl;
    return std::set<std::string>(); // Actor not found, return empty set
}

// Return a set of actor names which are all in the movieTitle
// If the passing in parameter: movieTitle is not in the database,
// display message and return an empty set
set<string> IMDB::find_actors_in_a_movie(string movieTitle) const
{
    auto it = movies_db.find(movieTitle); // Correctly use movies_db
    if (it != movies_db.end()) {
        return it->second; // Access the set of actors
    }

    cout << "Movie: " << movieTitle << " is not in the database" << endl;
    return std::set<std::string>(); // Movie not found, return empty set
}
