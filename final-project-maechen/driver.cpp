/**
 * driver - User interface of the IMBD-Movie-Database that allows users to search for movies based on their title and director
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "MovieHashTable.hpp"
#include "DirectorSkipList.hpp"

using namespace std;

// Function prototypes
MovieNode* parseMovieLine(string line);
void readMovieCSV(string filename,  MovieHashTable &movieTable, DirectorSkipList &directorList);
void display_menu();


/**
 * main - displays the menu, interacts with the user by reading user input, uses the Hash Table and Skip List functions
 * 
 * @param argc, argv
 * @return int
 */
int main(int argc, char* argv[]) {
   if(argc != 4){ // makes sure there is a valid number of arguments
        cout << "Invalid number of arguments." << endl;
        cout << "Usage: ./<program name> <csv file> <hashTable size> <skipList size>" << endl;
        return -1;
    }
    else{
        int ht_size = stoi(argv[2]);
        int sl_size = stoi(argv[3]);
        MovieHashTable ht(ht_size); // creating hash table object
        DirectorSkipList sl(sl_size, 10); // creating skip list object
        readMovieCSV(argv[1], ht, sl); // reads the csv file and converts into MovieNode objects
        int option;

        do{
            cout << "Number of collisions: " << ht.getCollisions() << endl;
            display_menu();
            cin >> option; // reading user input

            if(option <= 0 || option >= 6){ // checking for invalid input
                cout << "Invalid input. " << endl;
                return -1;
            }

            switch(option){ // directing user input
                case 1: // Find the director of a movie
                {
                    string title;
                    cout << "Enter movie name: " << endl;
                    getline(cin.ignore(), title);
                    MovieNode* movie = ht.search(title); // using hash table because it stores movie titles
                    if(movie != nullptr){
                        cout << "The director of " << movie->title << " is " << movie->director << endl;
                        cout << endl;
                    }
                    else{
                        cout << "Movie not found." << endl;
                        cout << endl;
                    }
                    break;
                }
                case 2: // Find the number of movies by a director
                {
                    string director;
                    cout << "Enter the name of the director:" << endl;
                    getline(cin.ignore(), director);
                    DirectorSLNode* movie = sl.search(director); // using skip list because it stores movie directors
                    if(movie != nullptr){ // if director is found
                        int number = 0;
                        for(int i = 0; i < movie->movies.size(); i++){ // iterates through vector of movies by that director
                            number++; // counting how many movies are in the movies vector
                        }
                        cout << movie->director << " directed " << number << " movie(s)." << endl;
                        cout << endl;
                    }
                    else {
                        cout << "Director not found." << endl;
                        cout << endl;
                    }
                    break;
                }
                case 3: // Find the description of a movie
                {
                    string title;
                    cout << "Enter the title of the movie: " << endl;
                    getline(cin.ignore(), title);
                    MovieNode* movie = ht.search(title);
                    if(movie != nullptr){
                        cout << "Summary: " << movie->title << " is a " << movie->year << " (" << movie->genre << ") film featuring \"" << movie->actors << "\". " << endl;
                        cout << "Plot: \"" << movie->description << ".\"" << endl;
                        cout << endl;
                    }
                    else{
                        cout << "Movie not found. " << endl;
                        cout << endl;
                    }
                    break;
                }
                case 4: // List the movies by a director
                {
                    string director;
                    cout << "Enter director name: " << endl;
                    getline(cin.ignore(), director);
                    DirectorSLNode* dir = sl.search(director);
                    if(dir != nullptr){
                        vector<MovieNode*> movies = dir->movies;
                        cout << dir->director << " directed the following movies: " << endl;
                        for(int i = 0; i < dir->movies.size(); i++){
                            cout << "     " << i << ": " << dir->movies[i]->title << endl;
                        }
                        cout << endl;
                    }
                    else{
                        cout << "Director not found." << endl;
                        cout << endl;
                    }
                    break;
                }
                case 5: // Quit
                {
                    return 0;
                    break;
                }
            }
        } while (option > 0 && option <= 5);
    }
    return 0;
}

/**
 * parseMovieLine - parses a CSV line into a MovieNode object
 * 
 * @param line
 * @return MovieNode*
 */
MovieNode* parseMovieLine(string line) {
    stringstream ss(line);
    vector<string> fields;
    string field;

    // Loop through the characters in the line
    bool in_quotes = false;
    for (size_t i = 0; i < line.length(); ++i) {
        char c = line[i];
        if (c == '\"') {
            in_quotes = !in_quotes;
        } else if (c == ',' && !in_quotes) {
            // add field to vector and reset for next field
            fields.push_back(field);
            field.clear();
        } else {
            field += c;
            // handle double quotes inside a quoted field
            if (in_quotes && c == '\"' && i < line.length() - 1 && line[i+1] == '\"') {
                field += '\"'; // add the second double quote and skip it
                ++i;
            }
        }
    }
    fields.push_back(field);

    if (fields.size() != 12) {
        cerr << "Error: Invalid movie line format" << line << endl;
        return nullptr;
    }

    int rank = stoi(fields[0]);
    string title = fields[1];
    string genre = fields[2];
    string description = fields[3];
    string director = fields[4];
    string actors = fields[5];
    int year = stoi(fields[6]);
    int runtime = stoi(fields[7]);
    float rating = stof(fields[8]);
    int votes = stoi(fields[9]);
    float revenue = stof(fields[10]);
    int metascore = stoi(fields[11]);

    // Create a new MovieNode object with the parsed fields
    MovieNode* movie = new MovieNode(rank, title, genre, description, director, actors, year, runtime, rating, votes, revenue, metascore);
    return movie;
}

/**
 * readMovieCSV - reads a CSV file into a vector of MovieNode objects
 * 
 * @param filename, movieTable, directorList
 * @return void
 */
void readMovieCSV(string filename,  MovieHashTable &movieTable, DirectorSkipList &directorList) {
    ifstream fin(filename); // creating ifstream object
    string line;

    if(fin.fail()) return; // if the file fails to open

    getline(fin, line); // stores each line into line variable

    while(getline(fin, line)){ // read each line until reaches an empty line
        MovieNode* movie = parseMovieLine(line); // creates a MovieNode object
        if(movie != nullptr){ 
            movieTable.insert(movie->title, movie); // add the title and movie object to hash table
            directorList.insert(movie->director, movie); // add the director and movie object to skip list
        }
    }

    fin.close(); // close file
}

/**
 * display_menu - displays the menu options
 * 
 * @param
 * @return void
 */
void display_menu() {
    cout << "Please select an option:" << endl;
    cout << "1. Find the director of a movie" << endl;
    cout << "2. Find the number of movies by a director" << endl;
    cout << "3. Find the description of a movie" << endl;
    cout << "4. List the movies by a director" << endl;
    cout << "5. Quit" << endl;
    cout << endl;
    cout << "Enter an Option: " << endl;
}