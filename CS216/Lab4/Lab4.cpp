/*
 * Course: CS216-00x
 * Project: Lab 4 (as part of Project 1)
 * Purpose: it reads data from an input file which passes as command line argument
 *          then stores in an object of IMDB class (to represent imdb database)
 *          it then allowes the user to search for all actors in either one of two movies
 *          two movies are from the user-input, then performs case insensitive matching
 *          and matches the movie titles from the database
 * Author: (your name)
 */

#include <iostream>
#include <limits>   //for numeric_limits
#include <fstream>
#include <string>
#include <cctype>
#include <set>
#include <map>
#include <sstream>
#include "imdb.h"

using namespace std;

void analyzeMovies(const IMDB& imdb);

int main(int argc, char* argv[])
{
    const int COMARGU_NUM = 1;
    // Check whether the number of command line arguments is exactly one 
    if (argc != COMARGU_NUM + 1)
    {
        cout << "Warning: need exactly " << COMARGU_NUM << " command line argument." << endl;
        cout << "Usage: " << argv[0] << " inputfile_name" << endl;
        return 1;
    }

    ifstream in_file;
    in_file.open(argv[1]);

    // Check whether the input file can be open successfully or not
    if (!in_file.good())
    {
        cout << "Warning: cannot open file named " << argv[1] << "!" << endl;
        return 2;
    }

    // Read data from the input file, assume "good data" from the input file
    // each line of the input file: actor name; movie1; movie2; ...; movieN;
    // read one line at a time then tokenize it:
    // create a pair <actor_name, the set of movieTitles which the actor was in>
    //        and insert to IMDB object
    IMDB cs216_imdb;

    while (!in_file.eof())
    {
        string line;
        getline(in_file, line);
        string actorName, movieTitle;
        // check if the text line is not empty then tokenize it
        if (line.length() != 0)
        {
            istringstream iss(line);
            getline(iss, actorName,';');

            // Extract extra white space
            iss>>ws;

            // Create a new set of movies associated with name
            set<string> movies;

            while (getline(iss, movieTitle, ';'))
            {
                movies.insert(movieTitle);
                // extract white space 
                iss>>ws;
            }
            // insert the pair to IMDB object: cs216_imdb
            cs216_imdb.insert_an_actor(actorName, movies);
        }
    }
    // close the input file
    in_file.close();

    int option;
    while (true)
    {
        bool validInput = true;
        cout << "Welcome to the CS216 IMDB APP!" << endl;
        cout << "This application stores information about Actors and their Movies, please choose your option (Enter Q or q to quit):" << endl;
        cout << "1. Actors in Movies" << endl;
        cout << "2. Actors and co-actors" << endl;
        cin >> option;

        if (cin.fail())
        {
            string input_to_check;
            cin.clear();
            cin >> input_to_check;
            if (input_to_check == "Q" || input_to_check == "q")
                break;
            else
            {
                cout << "Expecting a number as the option!" << endl;
                validInput = false;
            }
        }
        // get rid of anything left in the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // if there is a valid input option
        if (validInput)
        {
            switch (option)
            {
                case 1: analyzeMovies(cs216_imdb);
                        break;
                case 2: // leave it do nothing for Lab4
                        // we will complete it in Lab5
                        // Note that you need to finish this block for project1
                        break;
                default:
                        cout << "Invalid option number!" << endl;
            }
        }
    }
    cout << "Thank you for using CS216 IMDB APP!" << endl;
    return 0;
}


/* Purpose: this function asks the user to input two movie titles
 *          then finds the matched two movies from the database
 *          and displays all the actors in either of the two movies
 *          if no matched movie then display "Invalid movie title" and do nothing
 * @para imdb const IMDB&: represent the actorName-Movies database
 *          note that using const call by reference is for efficiency purpose:
 *               no copy of IMDB object is made and the argument has been protected
 * @return void
*/
void analyzeMovies(const IMDB& imdb)
{
    // Ask the user to input two movie titles to search for
    string movie1, movie2;
    cout << "Please input the first movie title: ";
    getline(cin,movie1);
    cout << "Please input the second movie title: ";
    getline(cin,movie2);
    // Check if both movie1 and movie2 can be matched with movies in the database
    // If either one is not, quit the program
    // Otherwise display all the actors in either of two movies
    //                   which are actually the union of two sets
    string matchedMovie1, matchedMovie2;
    matchedMovie1 = imdb.matchExistingMovie(movie1);
    matchedMovie2 = imdb.matchExistingMovie(movie2);
    // decide which one movie title is not valid
    bool notValid = false;
    if (matchedMovie1.length() == 0)
    {
        cout << "\" " << movie1 << " \"" << " is not a VALID movie title!" << endl;
        notValid = true;
    }
    if (matchedMovie2.length() == 0)
    {
        cout << "\" " << movie2 << " \"" << " is not a VALID movie title!" << endl;
        notValid = true;
    }
    if (notValid)
        return;
    // both movie titles are valid
    if (imdb.isExistingMovie(matchedMovie1) && imdb.isExistingMovie(matchedMovie2))
    {
        cout << "Your input matches the following two movies: " <<endl;
        cout << matchedMovie1 << endl;
        cout << matchedMovie2 << endl;
        cout << "Both movies are in the database, searching actors..." << endl;

        set<string> all;   // to store the union of actors_in_movie1 and actors_in_movie2
        all = imdb.find_actors_in_a_movie(matchedMovie1);
        set<string> actors_in_movie2 = imdb.find_actors_in_a_movie(matchedMovie2);
        for (auto i = actors_in_movie2.begin(); i != actors_in_movie2.end(); i++)
        {
            if (imdb.isExistingActor(*i))
                all.insert(*i);
            else
                cout << "isExistingActor function is not correct!!!" << endl;
        }
        // Display all the actors in either one movie
        cout << "All the actors in either of the two movies:" << endl;
        for (auto i = all.begin(); i != all.end(); i++)
            cout << *i << endl;
    }
    else
    {
        cout << "isExistingMovie function is not correct!!!" << endl;
        return;
    }
}

