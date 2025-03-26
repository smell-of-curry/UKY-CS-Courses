/*
 * Course: CS216-00x
 * Project: Lab 4 (as part of Project 1)
 * Purpose: Reads data from an input file (provided as a command line argument),
 *          builds an IMDB database (actor-to-movies mapping), and allows the user to
 *          search for actors by entering two movie titles. Matching is done in a 
 *          case-insensitive manner.
 * Author: Ean Lowell, Section 03
 */

 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <string>
 #include <set>
 #include <limits>
 #include <cstdlib>
 #include "imdb.h"
 
 using namespace std;
 
 // Function prototypes
 void analyzeMovies(const IMDB& imdb);
 void analyzeCoActors(const IMDB& imdb);
 
 int main(int argc, char* argv[])
 {
     // Check command line arguments
     if (argc != 2) {
         cout << "Warning: need exactly 1 command line argument." << endl;
         cout << "Usage: " << argv[0] << " inputfile_name" << endl;
         return 1;
     }
 
     ifstream inFile(argv[1]);
     if (!inFile.is_open()) {
         cout << "Warning: cannot open file named " << argv[1] << "!" << endl;
         return 2;
     }
 
     // Build the IMDB database.
     // Each line in the input file: actor; movie1; movie2; ...; movieN;
     IMDB cs216_imdb;
     string line;
     while (getline(inFile, line)) {
         if (line.empty())
             continue;
         istringstream iss(line);
         string actorName;
         if (!getline(iss, actorName, ';'))
             continue;  // skip malformed lines
 
         set<string> movies;
         string movieTitle;
         while (getline(iss, movieTitle, ';')) {
             if (!movieTitle.empty())
                 movies.insert(movieTitle);
         }
         cs216_imdb.insert_an_actor(actorName, movies);
     }
     inFile.close();
 
     // Main menu loop
     while (true)
     {
         cout << "\nWelcome to CS216 IMDB Finder!" << endl;
         cout << "This application stores information about Actors and their" << endl;
         cout << "Movies, please choose your option (Enter Q or q to quit):" << endl;
         cout << "1. Actors in Movies" << endl;
         cout << "2. Actors and co-actors" << endl;
         cout << "Your choice: ";
 
         string input;
         getline(cin, input);
         if (input == "Q" || input == "q")
             break;
 
         int option = 0;
         try {
             option = stoi(input);
         } catch (...) {
             cout << "Expecting a number as the option!" << endl;
             continue;
         }
         
         if (option != 1 && option != 2) {
             cout << "Invalid option number!" << endl;
             continue;
         }
 
         switch (option)
         {
             case 1:
                 analyzeMovies(cs216_imdb);
                 break;
             case 2:
                 analyzeCoActors(cs216_imdb);
                 break;
         }
     }
 
     cout << "Thank you for using my program, bye..." << endl;
     return 0;
 }
 
 /*
  * Function: analyzeMovies
  * Purpose: Ask the user to input two movie titles, match them in the database,
  *          and then repeatedly display a sub-menu until the user opts to go back.
  *          The sub-menu provides options:
  *             A -- Display the union (all actors in either movie)
  *             C -- Display the intersection (actors common to both movies)
  *             O -- Display the symmetric difference (actors only in one movie)
  *             B (or Q) -- Go back to the main menu.
  */
 void analyzeMovies(const IMDB& imdb)
 {
     // Prompt for movie titles.
     string movie1, movie2;
     cout << "\nPlease input the first movie title: ";
     getline(cin, movie1);
     cout << "Please input the second movie title: ";
     getline(cin, movie2);
 
     // Match movies (assume case-insensitive matching handled in IMDB::matchExistingMovie).
     string matchedMovie1 = imdb.matchExistingMovie(movie1);
     string matchedMovie2 = imdb.matchExistingMovie(movie2);
 
     bool invalid = false;
     if (matchedMovie1.empty()) {
         cout << "\" " << movie1 << " \" is not a VALID movie title!" << endl;
         invalid = true;
     }
     if (matchedMovie2.empty()) {
         cout << "\" " << movie2 << " \" is not a VALID movie title!" << endl;
         invalid = true;
     }
     if (invalid)
         return;
 
     if (imdb.isExistingMovie(matchedMovie1) && imdb.isExistingMovie(matchedMovie2))
     {
         cout << "\nYour input matches the following two movies:" << endl;
         cout << "  " << matchedMovie1 << endl;
         cout << "  " << matchedMovie2 << endl;
         cout << "Both movies are in the database, searching actors..." << endl;
         cout << "This is written by Ean Lowell. Enjoy THREE further searches." << endl;
     }
     else {
         cout << "Error: One or both movies are not in the database." << endl;
         return;
     }
 
     // Retrieve actor sets for each movie.
     set<string> actors1 = imdb.find_actors_in_a_movie(matchedMovie1);
     set<string> actors2 = imdb.find_actors_in_a_movie(matchedMovie2);
 
     // Compute union, intersection, and symmetric difference manually.
     set<string> unionActors, commonActors, diffActors;
     
     // UNION: add all actors from both sets.
     for (const auto &actor : actors1)
         unionActors.insert(actor);
     for (const auto &actor : actors2)
         unionActors.insert(actor);
 
     // INTERSECTION: actors in both sets.
     for (const auto &actor : actors1) {
         if (actors2.find(actor) != actors2.end())
             commonActors.insert(actor);
     }
     
     // SYMMETRIC DIFFERENCE: actors that are in union but not in intersection.
     for (const auto &actor : unionActors) {
         if (commonActors.find(actor) == commonActors.end())
             diffActors.insert(actor);
     }
 
     // Sub-menu loop for further searches.
     while (true) {
         cout << "\nPlease input your menu option (enter Q or q to quit)" << endl;
         cout << "A -- to print all the actors in either of the two movies." << endl;
         cout << "C -- to print all the common actors in both movies." << endl;
         cout << "O -- to print all the actors who are in only one movie, but not in both." << endl;
         cout << "Your option: ";
 
         string subOption;
         getline(cin, subOption);
         if (subOption == "B" || subOption == "b" || subOption == "Q" || subOption == "q")
             break;
         if (subOption != "A" && subOption != "a" &&
             subOption != "C" && subOption != "c" &&
             subOption != "O" && subOption != "o") {
             cout << "Invalid Option!" << endl;
             cout << "This is written by Ean Lowell. Enjoy THREE further searches." << endl;
             continue;
         }
 
         if (subOption == "A" || subOption == "a") {
             cout << "\nAll the actors in either of the two movies:" << endl;
             for (const auto& actor : unionActors)
                 cout << actor << endl;
        }
         else if (subOption == "C" || subOption == "c") {
             cout << "\nCommon actors in both movies:" << endl;
             for (const auto& actor : commonActors)
                 cout << actor << endl;
        }
         else if (subOption == "O" || subOption == "o") {
             cout << "\nActors only in one of two movies:" << endl;
             for (const auto& actor : diffActors)
                 cout << actor << endl;
         }
     }
 }
 
 /*
  * Function: analyzeCoActors
  * Purpose: Ask the user to type an actor's name, then, if valid, display for each movie that actor
  *          is in, the list of co-actors (excluding the actor themself).
  */
 void analyzeCoActors(const IMDB& imdb)
 {
     cout << "This is written by Ean Lowell, and I hope you enjoy the Finder." << endl;
     cout << "Finding the co-actors for (please enter the actor's name) -" << endl;
     cout << "-> ";
     string actor_name;
     getline(cin, actor_name);
     if (!imdb.isExistingActor(actor_name))
     {
         cout << "The actor name you entered is not in the database." << endl;
         return;
     }   
 
     set<string> movies_of_actor = imdb.find_movies_for_an_actor(actor_name);
     for (const auto &movie : movies_of_actor)
     {
         cout << "The co-actors of " << actor_name << " in the movie \"" << movie << "\" are:" << endl;
         set<string> coactors = imdb.find_actors_in_a_movie(movie);
         for (const auto &actor : coactors)
         {
             if (actor == actor_name)
                 continue;
             cout << actor << endl;
         }
         cout << "***********************************" << endl;
     }
 }
 