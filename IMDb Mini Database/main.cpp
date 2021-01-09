// Code is by no means perfect and really improvable. Main focus was to master the linked list data structure

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

// Data part of a movie node
class Movie {
public:
    string movieTitle;
    string genres;
    int titleYear;
    float imdbScore;
    string directorName;
    int directorFacebookLikes;
    int criticsForReview;
    int duration;
    string actor1Name;
    int actor1FacebookLikes;
    string actor2Name;
    int actor2FacebookLikes;
    string actor3Name;
    int actor3FacebookLikes;
    long long gross;
    int votedUsers;
    int castTotalFacebookLikes;
    int facesInPoster;
    string plotKeywords;
    string movieImdbLink;
    int numUsersForReviews;
    string language;
    string country;
    string contentRating;
    long long budget;
    float aspectRatio;
    int movieFacebookLikes;
    string color;

    // Empty default constructor because the program will not run without it
    Movie() {};

    //Constructor for the movie class
    Movie(string movie_title, string genres, int title_year, float imdb_score, string director_name,
          int director_facebook_likes,
          int critics_for_review, int duration, string actor_1_name, int actor_1_facebook_likes, string actor_2_name,
          int actor_2_facebook_likes,
          string actor_3_name, int actor_3_facebook_likes, long long gross, int voted_users,
          int cast_total_facebook_likes,
          int faces_in_poster, string plot_keywords, string movie_imdb_link, int num_users_for_reviews, string language,
          string country, string content_rating, long long budget, float aspect_ratio, int movie_facebook_likes,
          string colour) {
        //initializing
        movieTitle = movie_title;
        this->genres = genres;
        titleYear = title_year;
        imdbScore = imdb_score;
        directorName = director_name;
        directorFacebookLikes = director_facebook_likes;
        criticsForReview = critics_for_review;
        this->duration = duration;
        actor1Name = actor_1_name;
        actor1FacebookLikes = actor_1_facebook_likes;
        actor2Name = actor_2_name;
        actor2FacebookLikes = actor_2_facebook_likes;
        actor3Name = actor_3_name;
        actor3FacebookLikes = actor_3_facebook_likes;
        this->gross = gross;
        votedUsers = voted_users;
        castTotalFacebookLikes = cast_total_facebook_likes;
        facesInPoster = faces_in_poster;
        plotKeywords = plot_keywords;
        movieImdbLink = movie_imdb_link;
        numUsersForReviews = num_users_for_reviews;
        this->language = language;
        this->country = country;
        contentRating = content_rating;
        this->budget = budget;
        aspectRatio = aspect_ratio;
        movieFacebookLikes = movie_facebook_likes;
        this->color = colour;
    }

    void PrintMovieData() {
        cout << endl;
        cout << "Movie title: " << movieTitle << endl;
        cout << "Genres: " << genres << endl;

        if (titleYear != -1)
            cout << "Released in: " << titleYear << endl;
        else
            cout << "Release year unknown." << endl;

        if (imdbScore != -1)
            cout << "IMDB Rating: " << imdbScore << endl;
        else
            cout << "IMDB Rating unknown." << endl;

        if (!directorName.empty())
            cout << "Directed by: " << directorName << endl;
        else
            cout << "Director name unknown." << endl;

        if (directorFacebookLikes != -1)
            cout << "Director's Facebook likes: " << directorFacebookLikes << endl;
        else
            cout << "Director's Facebook likes unknown." << endl;

        if (criticsForReview != -1)
            cout << "Critics For Review: " << criticsForReview << endl;
        else
            cout << "Critics for reviews unknown." << endl;

        if (duration != -1)
            cout << "Duration: " << duration << " minutes" << endl;
        else
            cout << "Duration unknown." << endl;

        if (!actor1Name.empty())
            cout << "Actor 1 name: " << actor1Name << endl;
        else
            cout << "First actor name unknown." << endl;

        if (!actor2Name.empty())
            cout << "Actor 2 name: " << actor2Name << endl;
        else
            cout << "Second actor name unknown." << endl;

        if (!actor3Name.empty())
            cout << "Actor 3 name: " << actor3Name << endl;
        else
            cout << "Third actor name unknown." << endl;

        if (gross != -1)
            cout << "Gross: " << gross << " $" << endl;
        else
            cout << "Gross unknown." << endl;

        if (votedUsers != -1)
            cout << "Users Voted: " << votedUsers << endl;
        else
            cout << "Unknown number of users voted." << endl;

        if (castTotalFacebookLikes != -1)
            cout << "Cast Total Facebook Likes: " << castTotalFacebookLikes << endl;
        else
            cout << "Unknown cast Facebook likes." << endl;

        if (facesInPoster != -1)
            cout << "Faces in the movie poster: " << facesInPoster << endl;
        else
            cout << "Unknown number of faces in poster." << endl;

        if (!plotKeywords.empty())
            cout << "Keywords: " << plotKeywords << endl;
        else
            cout << "Unknown plot keywords." << endl;

        if (!movieImdbLink.empty())
            cout << "IMDB Link: " << movieImdbLink << endl;
        else
            cout << "Movie IMDB link not found." << endl;

        if (numUsersForReviews != -1)
            cout << "Number of Reviews: " << numUsersForReviews << endl;
        else
            cout << "Unknown number of reviews." << endl;

        if (language.empty())
            cout << "Language: " << language << endl;
        else
            cout << "Language unknown." << endl;

        if (!country.empty())
            cout << "Country: " << country << endl;
        else
            cout << "Country unknown." << endl;

        if (!contentRating.empty())
            cout << "Content Rating: " << contentRating << endl;
        else
            cout << "Unknown content rating." << endl;

        if (budget != -1)
            cout << "Budget: " << budget << " $" << endl;
        else
            cout << "Budget unknown." << endl;

        if (aspectRatio != -1)
            cout << "Aspect Ratio: " << aspectRatio << endl;
        else
            cout << "Aspect Ration unknown." << endl;

        if (movieFacebookLikes != -1)
            cout << "Movie Facebook Likes: " << movieFacebookLikes << endl;
        else
            cout << "Movie Facebook likes unknown." << endl;

        if (!color.empty())
            cout << "Colored or in Black and White: " << color << endl;
        else
            cout << "Unknown color format." << endl;
    }
};

// Node for each list
template<class Type>
class Node {
public:
    Type *pData;
    Node *pNext;

    Node() {
        pNext = nullptr;
    }
};

// List of movies a director has directed
class MoviesDirectedList {
public:
    Node<Movie> *pStart;
    Node<Movie> *pLast;

    MoviesDirectedList() {
        pStart = nullptr;
        pLast = nullptr;
    }

    void InsertMovie(Movie *pMovie) { // O(1)
        auto *node = new Node<Movie>();
        node->pData = pMovie;

        if (pStart == nullptr) {
            pStart = node;
            pLast = node;
        } else {
            pLast->pNext = node;
            pLast = node;
        }
    }

    // Print the list of movies a director has directed
    void PrintList() { // O(n)
        Node<Movie> *pMovieNode;
        pMovieNode = pStart;
        while (pMovieNode != nullptr) {
            cout << pMovieNode->pData->movieTitle << endl;
            pMovieNode = pMovieNode->pNext;
        }
    }
};

// The data part of a director node
class Director {
public:
    string name;
    MoviesDirectedList *pMoviesDirectedList; // Every director has his/her own list of movies directed

    Director() {
        name = "";
    }

    Director(string name) {
        this->name = name;
        pMoviesDirectedList = new MoviesDirectedList();
    }
};

// A list of all the director nodes
class DirectorList {
public:
    Node<Director> *pStart;
    Node<Director> *pLast;
    Node<Director> *pCurrentNode; // Used to hold location of a certain node after search operation

    DirectorList() {
        pStart = nullptr;
        pLast = nullptr;
        pCurrentNode = nullptr;
    }

    void Insert(string directorName, Movie *pMovie) { // O(n)
        if (IsDirectorInList(directorName)) {
            pCurrentNode->pData->pMoviesDirectedList->InsertMovie(pMovie);
            return;
        }

        Director *pDirector = new Director(directorName);

        auto *pNode = new Node<Director>();
        pNode->pData = pDirector;
        pNode->pData->pMoviesDirectedList->InsertMovie(pMovie);
        if (pStart == nullptr) {
            pStart = pNode;
            pLast = pNode;
        } else {
            pLast->pNext = pNode;
            pLast = pNode;
        }
    }

    bool IsDirectorInList(string directorName) { // O(n)
        if (pStart == nullptr)
            return false;

        Node<Director> *pDirectorNode;
        pDirectorNode = pStart;

        while (pDirectorNode != nullptr) {
            if (pDirectorNode->pData->name == directorName) {
                pCurrentNode = pDirectorNode;
                return true;
            }
            pDirectorNode = pDirectorNode->pNext;
        }
        return false;
    }

    void PrintDirectorList() { // O(n)
        Node<Director> *pDirectorNode;
        pDirectorNode = pStart;
        while (pDirectorNode != nullptr) {
            cout << pDirectorNode->pData->name << endl;
            pDirectorNode = pDirectorNode->pNext;
            cout << endl;
        }
    }

    void DirectedMovies(string directorName) { // O(n)
        Node<Director> *pDirectorNode;
        pDirectorNode = pStart;

        while (pDirectorNode != nullptr) {
            if (pDirectorNode->pData->name == directorName) {
                pCurrentNode = pDirectorNode;
                break;
            }
            pDirectorNode = pDirectorNode->pNext;
        }

        if (pDirectorNode == nullptr) {
            cout << "Director is not present in the list.\n";
            return;
        }

        cout << directorName << " has directed:\n";
        pCurrentNode->pData->pMoviesDirectedList->PrintList();
    }
};

// List of movies an actor has acted in
class MoviesActedInList { // Sorted by year
public:

    Node<Movie> *pStart;
    Node<Movie> *pLast;

    Node<Movie> *pCurrentNode;
    Node<Movie> *pCurrentNodePred;

    MoviesActedInList() {
        pStart = nullptr;
        pLast = nullptr;
        pCurrentNode = nullptr;
        pCurrentNodePred = nullptr;
    }

    void InsertAtFront(Movie *pMovie) {
        auto *pMovieNode = new Node<Movie>();
        pMovieNode->pData = pMovie;

        // If the list was empty then first node is Start and Last
        if (pStart == nullptr) {
            pStart = pMovieNode;
            pLast = pMovieNode;
        } else {    // else fit it in the Start and make it Start
            pMovieNode->pNext = pStart;
            pStart = pMovieNode;
        }
    }

    void InsertAtEnd(Movie *pMovie) {
        auto *pMovieNode = new Node<Movie>();
        pMovieNode->pData = pMovie;

        if (pStart == nullptr) {
            pStart = pMovieNode;
            pLast = pMovieNode;
        } else {
            pLast->pNext = pMovieNode;
            pLast = pMovieNode;
        }
    }

    void Search(int value) { // O(n)
        pCurrentNode = pStart;
        pCurrentNodePred = nullptr;

        while (pCurrentNode != nullptr && pCurrentNode->pData->titleYear < value) {
            pCurrentNodePred = pCurrentNode;
            pCurrentNode = pCurrentNode->pNext;
        }
    }

    void InsertMovie(Movie *pMovie) { // O(n)
        Search(pMovie->titleYear);

        if (pCurrentNodePred ==
            nullptr) {
            InsertAtFront(pMovie);
            return;
        } else {
            if (pCurrentNodePred->pNext == nullptr) {
                InsertAtEnd(pMovie);
                return;
            } else {
                auto *pMovieNode = new Node<Movie>();
                pMovieNode->pData = pMovie;

                pMovieNode->pNext = pCurrentNodePred->pNext;
                pCurrentNodePred->pNext = pMovieNode;
            }
        }
    }

    void PrintList() { // O(n)
        Node<Movie> *pMovieNode;
        pMovieNode = pStart;
        while (pMovieNode != nullptr) {
            cout << pMovieNode->pData->movieTitle << "  " << pMovieNode->pData->titleYear << endl;
            pMovieNode = pMovieNode->pNext;
        }
    }

    void PrintCoActors(string actorName) { // O(n)
        Node<Movie> *pMovieNode;
        cout << "Co-Actors of " << actorName << " are: " << endl;
        pMovieNode = pStart;

        while (pMovieNode != nullptr) {

            // Check all the actor fields because the desired actor can appear in any of the slots
            // If the name is not equal to desired actor's name then print because then he/she is a co-actor of the actor
            if (!(pMovieNode->pData->actor1Name == actorName)) {
                cout << pMovieNode->pData->actor1Name << " in the movie " << pMovieNode->pData->movieTitle << endl;
            }
            if (!(pMovieNode->pData->actor2Name == actorName)) {
                cout << pMovieNode->pData->actor2Name << " in the movie " << pMovieNode->pData->movieTitle << endl;
            }
            if (!(pMovieNode->pData->actor3Name == actorName)) {
                cout << pMovieNode->pData->actor3Name << " in the movie " << pMovieNode->pData->movieTitle << endl;
            }
            cout << endl;
            pMovieNode = pMovieNode->pNext;
        }
    }

    void PrintUniqueCoActors(string actorName) { // O(n^2)
        Node<Movie> *pMovieNode;
        pMovieNode = pStart;
        string uniqueCoActors[200]; // Stores the name of the co actor that has appeared once, size is enough for our data set
        int i = 0;

        cout << "Unique Co-Actors of " << actorName << " are:" << endl;
        while (pMovieNode != nullptr) {
            if (IsCoActorUnique(uniqueCoActors, 200, pMovieNode->pData->actor1Name) &&
                !(pMovieNode->pData->actor1Name ==
                  actorName)) { // If co-actor is unique, print the name and add it to the array
                cout << pMovieNode->pData->actor1Name << " in  movie " << pMovieNode->pData->movieTitle << endl;
                uniqueCoActors[i] = pMovieNode->pData->actor1Name;
                i++;
            }

            if (IsCoActorUnique(uniqueCoActors, 200, pMovieNode->pData->actor2Name) &&
                !(pMovieNode->pData->actor2Name == actorName)) {
                cout << pMovieNode->pData->actor2Name << " in  movie " << pMovieNode->pData->movieTitle << endl;
                uniqueCoActors[i] = pMovieNode->pData->actor2Name;
                i++;
            }

            if (IsCoActorUnique(uniqueCoActors, 200, pMovieNode->pData->actor3Name) &&
                !(pMovieNode->pData->actor3Name == actorName)) {
                cout << pMovieNode->pData->actor3Name << "  in  movie " << pMovieNode->pData->movieTitle << endl;
                uniqueCoActors[i] = pMovieNode->pData->actor3Name;
                i++;
            }
            pMovieNode = pMovieNode->pNext;
        }
    }

    // Returns a list of unique co actors of an actor
    string *getUniqueCoActors(string actorName) { // O(n^2)

        Node<Movie> *pMovieNode;
        pMovieNode = pStart;
        auto *uniqueCoActors = new string[200];

        int i = 0;
        while (pMovieNode != nullptr) {
            if (IsCoActorUnique(uniqueCoActors, 200, pMovieNode->pData->actor1Name) &&
                !(pMovieNode->pData->actor1Name == actorName)) {
                uniqueCoActors[i] = pMovieNode->pData->actor1Name;
                i++;
            }
            if (IsCoActorUnique(uniqueCoActors, 200, pMovieNode->pData->actor2Name) &&
                !(pMovieNode->pData->actor2Name == actorName)) {
                uniqueCoActors[i] = pMovieNode->pData->actor2Name;
                i++;

            }
            if (IsCoActorUnique(uniqueCoActors, 200, pMovieNode->pData->actor3Name) &&
                !(pMovieNode->pData->actor3Name == actorName)) {
                uniqueCoActors[i] = pMovieNode->pData->actor3Name;
                i++;
            }
            pMovieNode = pMovieNode->pNext;
        }
        return uniqueCoActors;
    }

    bool IsCoActorUnique(string *actorsAppeared, int sizeOfArray, string actorName) { // O(n)
        for (int i = 0; i < sizeOfArray; i++) {
            if (actorsAppeared[i] == actorName) {
                return false;
            }
        }
        return true;
    }
};

// The data part of an actor node
class Actor {
public:
    string actorName;
    int facebookLikes;
    MoviesActedInList *pMoviesActedInList; // Every actor has his/her own list of movies they acted in, sorted by year

    Actor() {
        actorName = "";
        facebookLikes = -1;
    }

    Actor(string name, int likes) {
        actorName = name;
        facebookLikes = likes;
        pMoviesActedInList = new MoviesActedInList();
    }
};

// A list of all the unique actors
class ActorList {
public:
    Node<Actor> *pStart;
    Node<Actor> *pLast;
    Node<Actor> *pCurrentNode;

    ActorList() {
        pStart = nullptr;
        pLast = nullptr;
        pCurrentNode = nullptr;
    }

    void Insert(string actorName, int facebookLikes, Movie *movie) { // O(n) because of IsActorInList function
        if (IsActorInList(actorName)) { // If actor has appeared again then update his/her movie list and return
            pCurrentNode->pData->pMoviesActedInList->InsertMovie(movie);
            return;
        }

        // Program has reached this point which means actor has appeared for the first time which means create a new object and add the movie to his/her movie list
        auto *actor = new Actor(actorName, facebookLikes);

        auto *pActorNode = new Node<Actor>();
        pActorNode->pData = actor;
        pActorNode->pData->pMoviesActedInList->InsertMovie(movie);
        if (pStart == nullptr) {
            pStart = pActorNode;
            pLast = pActorNode;
        } else {
            pLast->pNext = pActorNode;
            pLast = pActorNode;
        }
    }

    bool IsActorInList(string actorName) { // To check if actor has appeared for the first time or not
        if (pStart == nullptr)
            return false;

        Node<Actor> *pActorNode;
        pActorNode = pStart;

        while (pActorNode != nullptr) {
            if (pActorNode->pData->actorName == actorName) {
                pCurrentNode = pActorNode; // Actor has appeared again so store his/her node in pCurrentNode and return (pCurrentNode is used to update the movie list afterwards)
                return true;
            }
            pActorNode = pActorNode->pNext;
        }

        return false;
    }

    // Print the names of unique actors
    void PrintActorList() { // O(n)
        Node<Actor> *pActorNode;
        pActorNode = pStart;
        while (pActorNode != nullptr) {
            cout << pActorNode->pData->actorName << endl;
            pActorNode = pActorNode->pNext;
            cout << endl;
        }
    }

    // Print the list of movies an actor has acted in
    void PrintActorActedIn(string actorName) { // O(n)
        Node<Actor> *pActorNode;
        pActorNode = pStart;

        // Find desired actor's node
        while (pActorNode != nullptr) {
            if (pActorNode->pData->actorName == actorName) {
                pCurrentNode = pActorNode;
                break;
            }
            pActorNode = pActorNode->pNext;
        }

        // Check if it exists
        if (pActorNode == nullptr) {
            cout << "Actor was not found in the list.\n";
            return;
        }

        cout << actorName << " has acted in:\n";
        pCurrentNode->pData->pMoviesActedInList->PrintList(); // Call the actor's printMovie list function
    }

    // Print all co-actors of an actor and the movie they acted in together
    void PrintCoActors(string actorName) { // O(n)
        Node<Actor> *pActorNode;
        pActorNode = pStart;

        while (pActorNode != nullptr) {
            if (pActorNode->pData->actorName == actorName) {
                pCurrentNode = pActorNode;
                break;
            }
            pActorNode = pActorNode->pNext;
        }

        if (pActorNode == nullptr) {
            cout << "Actor was not found in the list.\n";
            return;
        }

        pCurrentNode->pData->pMoviesActedInList->PrintCoActors(actorName);
    }


    void PrintUniqueCoActors(string actorName) { // O(n)
        Node<Actor> *pActorNode;
        pActorNode = pStart;

        while (pActorNode != nullptr) {
            if (pActorNode->pData->actorName == actorName) {
                pCurrentNode = pActorNode;
                break;
            }
            pActorNode = pActorNode->pNext;
        }

        if (pActorNode == nullptr) {
            cout << "Actor was not found in the list.\n";
            return;
        }

        pCurrentNode->pData->pMoviesActedInList->PrintUniqueCoActors(actorName);
    }

    void PrintCoActorsOfCoActors(string actorname) { // O(n^3) yikes
        Node<Actor> *pActorNode;
        pActorNode = pStart;
        auto *uniqueCoActors = new string[200];

        while (pActorNode != nullptr) {
            if (pActorNode->pData->actorName == actorname) {
                pCurrentNode = pActorNode;
                break;
            }
            pActorNode = pActorNode->pNext;
        }

        if (pActorNode == nullptr) {
            cout << "Actor was not found in the list.\n";
            return;
        }

        // Get actor's unique list of co-actors
        uniqueCoActors = pCurrentNode->pData->pMoviesActedInList->getUniqueCoActors(pCurrentNode->pData->actorName);

        pActorNode = pStart;
        int i = 0;

        while (!uniqueCoActors[i].empty() && i < 200) {
            while (pActorNode != nullptr) {
                if (pActorNode->pData->actorName == uniqueCoActors[i]) {
                    pCurrentNode = pActorNode;
                    break;
                }
                pActorNode = pActorNode->pNext;
            }
            pCurrentNode->pData->pMoviesActedInList->PrintCoActors(pCurrentNode->pData->actorName);
            pActorNode = pStart;
            i++;
        }
    }

    void areCoActors(string actor1Name, string actor2Name) {

        Node<Actor> *pActorNode;
        pActorNode = pStart;
        // Find the node for actor 1
        while (pActorNode != nullptr) {
            if (pActorNode->pData->actorName == actor1Name) {
                pCurrentNode = pActorNode;
                break;
            }
            pActorNode = pActorNode->pNext;
        }

        if (pActorNode == nullptr) {
            cout << "Actor was not found in the list.\n";
            return;
        }

        Node<Movie> *pMovieNode = pCurrentNode->pData->pMoviesActedInList->pStart;
        bool have_acted_together = false;
        // Using the node of actor one, access his/her movie list and compare actor 2's name with actor 1's co actors
        while (pMovieNode != nullptr) {
            if (pMovieNode->pData->actor1Name == actor2Name) {
                cout << actor1Name << " and " << actor2Name << " have worked together in "
                     << pMovieNode->pData->movieTitle << endl;
                have_acted_together = true;
            } else if (pMovieNode->pData->actor2Name == actor2Name) {
                cout << actor1Name << " and " << actor2Name << " have worked together in "
                     << pMovieNode->pData->movieTitle << endl;
                have_acted_together = true;
            } else if (pMovieNode->pData->actor3Name == actor2Name) {
                cout << actor1Name << " and " << actor2Name << " have worked together in "
                     << pMovieNode->pData->movieTitle << endl;
                have_acted_together = true;
            }
            pMovieNode = pMovieNode->pNext;
        }

        if (!have_acted_together)
            cout << "These two have never acted together.\n";
    }
};

// A list of all the movies (contains actors list and directors list)
class MovieList {
public:
    Movie *thisMovieObject;
    ActorList *actorList;
    DirectorList *directorList;

    string filePath;
    string oneLine;
    string movieTitle;
    string genres;
    int titleYear;
    float imdbScore;
    string directorName;
    int directorFacebookLikes;
    int criticsForReview;
    int duration;
    string actor1Name;
    int actor1FacebookLikes;
    string actor2Name;
    int actor2FacebookLikes;
    string actor3Name;
    int actor3FacebookLikes;
    long long gross;
    int votedUsers;
    int castTotalFacebookLikes;
    int facesInPoster;
    string plotKeywords;
    string movieImdbLink;
    int numUsersForReviews;
    string language;
    string country;
    string contentRating;
    long long budget;
    float aspectRatio;
    int movieFacebookLikes;
    string color;

    // Maintaining two movie lists, sorted by year and rating
    Node<Movie> *pStartOfSortedByYear = nullptr;
    Node<Movie> *pLastOfSortedByYear = nullptr;
    Node<Movie> *pStartOfSortedByRating = nullptr;
    Node<Movie> *pLastOfSortedByRating = nullptr;
    Node<Movie> *pCurrentNode = nullptr;
    Node<Movie> *pCurrentNodePrev = nullptr;

    MovieList(string filePath) {
        this->filePath = filePath;
        ifstream movieFile(this->filePath);
        string temp; // To store the string values which are converted to the correct datatype later

        actorList = new ActorList();
        directorList = new DirectorList();

        if (!movieFile.is_open())
            cout << "File failed to open.";

        bool title_line = true;
        while (getline(movieFile, oneLine)) {
            if (!title_line) {
                stringstream current_line(oneLine);

                getline(current_line, movieTitle, '/');

                getline(current_line, temp, ','); // Skip the next comma

                getline(current_line, genres, ',');

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    titleYear = -1;
                } else {
                    titleYear = stoi(temp);
                }

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    imdbScore = -1;
                } else {
                    imdbScore = stof(temp);
                }

                getline(current_line, directorName, ',');

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    directorFacebookLikes = -1;
                } else {
                    directorFacebookLikes = stoi(temp);
                }

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    criticsForReview = -1;
                } else {
                    criticsForReview = stoi(temp);
                }

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    duration = -1;
                } else {
                    duration = stoi(temp);
                }

                getline(current_line, actor1Name, ',');

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    actor1FacebookLikes = -1;
                } else {
                    actor1FacebookLikes = stoi(temp);
                }

                getline(current_line, actor2Name, ',');

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    actor2FacebookLikes = -1;
                } else {
                    actor2FacebookLikes = stoi(temp);
                }

                getline(current_line, actor3Name, ',');

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    actor3FacebookLikes = -1;
                } else {
                    actor3FacebookLikes = stoi(temp);
                }

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    gross = -1;
                } else {
                    gross = stoll(temp);
                }

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    votedUsers = -1;
                } else {
                    votedUsers = stoi(temp);
                }

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    castTotalFacebookLikes = -1;
                } else {
                    castTotalFacebookLikes = stoi(temp);
                }

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    facesInPoster = -1;
                } else {
                    facesInPoster = stoi(temp);
                }

                getline(current_line, plotKeywords, ',');

                getline(current_line, movieImdbLink, ',');

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    numUsersForReviews = -1;
                } else {
                    numUsersForReviews = stoi(temp);
                }

                getline(current_line, language, ',');

                getline(current_line, country, ',');

                getline(current_line, contentRating, ',');

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    budget = -1;
                } else {
                    budget = stoll(temp);
                }

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    aspectRatio = -1;
                } else {
                    aspectRatio = stof(temp);
                }

                getline(current_line, temp, ',');
                if (temp.empty()) {
                    movieFacebookLikes = -1;
                } else {
                    movieFacebookLikes = stoi(temp);
                }

                getline(current_line, color, ',');

                thisMovieObject = new Movie(movieTitle, genres, titleYear, imdbScore, directorName,
                                            directorFacebookLikes,
                                            criticsForReview, duration, actor1Name, actor1FacebookLikes,
                                            actor2Name, actor2FacebookLikes,
                                            actor3Name, actor3FacebookLikes, gross, votedUsers,
                                            castTotalFacebookLikes,
                                            facesInPoster, plotKeywords, movieImdbLink, numUsersForReviews,
                                            language,
                                            country, contentRating, budget, aspectRatio, movieFacebookLikes,
                                            color);

                // Insert the actors, director and the movie into the respective lists
                actorList->Insert(actor1Name, actor1FacebookLikes, thisMovieObject);
                actorList->Insert(actor2Name, actor2FacebookLikes, thisMovieObject);
                actorList->Insert(actor3Name, actor3FacebookLikes, thisMovieObject);
                directorList->Insert(directorName, thisMovieObject);
                InsertSortedByYear(thisMovieObject);
                InsertByRating(thisMovieObject);
            } else { // Get rid of the 1st row because it only has headings. The cursor moves to the second row after the pNext line is executed.
                stringstream titles(oneLine);
                title_line = false;
            }
        }
        movieFile.close(); // **Good programming practice**
    }

    // Search a movie by title
    void MovieDetail(string movietitle) { // O(n)
        bool isFound = false;
        auto *pMovieNode = new Node<Movie>();
        pMovieNode = pStartOfSortedByYear;
        while (pMovieNode != nullptr) {
            if (pMovieNode->pData->movieTitle == movietitle) {
                cout << "----------- Movie found ---------------- " << endl;
                pMovieNode->pData->PrintMovieData();
                isFound = true;
                break;
            }
            pMovieNode = pMovieNode->pNext;
        }

        if (!isFound) {
            cout << " MOVIE NOT FOUND " << endl;
        }
    }

    // Print movies released in a given year
    void MoviesInGivenYear(int year) { // O(n)
        if (year < 1916 || year > 2016) {
            cout << "\nWe only have movies from 1916 till 2016.\n";
            return;
        }

        Node<Movie> *pMovieNode;
        pMovieNode = pStartOfSortedByYear;
        bool found_movies = false;
        while (pMovieNode != nullptr) {
            if (pMovieNode->pData->titleYear == year) {
                cout << pMovieNode->pData->movieTitle << endl;
                found_movies = true;
            }

            pMovieNode = pMovieNode->pNext;

            if (pMovieNode->pData->titleYear > year)
                break;
        }

        if (!found_movies)
            cout << "Found no movies in " << year << " :(" << endl;
    }

    void InsertAtFrontByYear(Movie *pMovie) { // O(1)
        auto *pMovieNode = new Node<Movie>();
        pMovieNode->pData = pMovie;

        // If the list was empty then first node is Start and Last
        if (pStartOfSortedByYear == nullptr) {
            pStartOfSortedByYear = pMovieNode;
            pLastOfSortedByYear = pMovieNode;
        } else {    // else fit it in the Start and make it Start
            pMovieNode->pNext = pStartOfSortedByYear;
            pStartOfSortedByYear = pMovieNode;
        }
    }

    void InsertAtEndByYear(Movie *pMovie) { // O(1)
        auto *pMovieNode = new Node<Movie>();
        pMovieNode->pData = pMovie;

        if (pStartOfSortedByYear == nullptr) {
            pStartOfSortedByYear = pMovieNode;
            pLastOfSortedByYear = pMovieNode;
        } else {
            pLastOfSortedByYear->pNext = pMovieNode;
            pLastOfSortedByYear = pMovieNode;
        }
    }

    // For maintaining the movie list by year
    void SearchYear(int year) { // O(n)
        pCurrentNode = pStartOfSortedByYear;
        pCurrentNodePrev = nullptr;

        while (pCurrentNode != nullptr && pCurrentNode->pData->titleYear < year) {
            pCurrentNodePrev = pCurrentNode;
            pCurrentNode = pCurrentNode->pNext;
        }
    }

    void InsertSortedByYear(Movie *pMovie) { // O(n)
        SearchYear(pMovie->titleYear);

        if (pCurrentNodePrev == nullptr) {
            InsertAtFrontByYear(pMovie);
            return;
        } else {
            if (pCurrentNodePrev->pNext == nullptr) {
                InsertAtEndByYear(pMovie);
                return;
            } else {
                auto *pMovieNode = new Node<Movie>();
                pMovieNode->pData = pMovie;

                pMovieNode->pNext = pCurrentNodePrev->pNext;
                pCurrentNodePrev->pNext = pMovieNode;
            }
        }
    }

    // Print the whole list (uses sorted by year list)
    void PrintListByYear(bool increasingOrder = true) { // O(n)
        if (increasingOrder) {
            if (pStartOfSortedByYear == nullptr) {
                cout << "List is empty. Nothing to print.\n";
                return;
            }

            Node<Movie> *pMovieNode;
            pMovieNode = pStartOfSortedByYear;
            while (pMovieNode != nullptr) {
                if (pMovieNode->pData->titleYear != -1) {
                    cout << pMovieNode->pData->movieTitle << " " << pMovieNode->pData->titleYear << endl;
                } else {
                    cout << pMovieNode->pData->movieTitle << "  " << "(Release Year Unknown)" << endl;
                }
                pMovieNode = pMovieNode->pNext;
            }
            cout << endl;
        } else {
            PrintSortedByYearDecreasing(pStartOfSortedByYear);
        }
    }

    // Print the sorted by year list in reverse using recursion
    void PrintSortedByYearDecreasing(Node<Movie> *pStart) { // O(n)
        if (pStart == nullptr)
            return;
        PrintSortedByYearDecreasing(pStart->pNext);
        if (pStart->pData->titleYear != -1)
            cout << pStart->pData->movieTitle << " " << pStart->pData->titleYear << endl;
        else
            cout << pStart->pData->movieTitle << " " << "(Release Year Unknown)" << endl;
    }

    void InsertAtFrontByRating(Movie *pMovie) { // O(1)
        auto *pMovieNode = new Node<Movie>();
        pMovieNode->pData = pMovie;

        // If the list was empty then first node is Start and Last
        if (pStartOfSortedByRating == nullptr) {
            pStartOfSortedByRating = pMovieNode;
            pLastOfSortedByRating = pMovieNode;
        } else {    // else fit it in the Start and make it Start
            pMovieNode->pNext = pStartOfSortedByRating;
            pStartOfSortedByRating = pMovieNode;
        }
    }

    void InsertAtEndByRating(Movie *pMovie) { // O(1)
        auto *pMovieNode = new Node<Movie>();
        pMovieNode->pData = pMovie;

        if (pStartOfSortedByRating == nullptr) {
            pStartOfSortedByRating = pMovieNode;
            pLastOfSortedByRating = pMovieNode;
        } else {
            pLastOfSortedByRating->pNext = pMovieNode;
            pLastOfSortedByRating = pMovieNode;
        }
    }

    void SearchRating(float rating) { // O(n)
        pCurrentNode = pStartOfSortedByRating;
        pCurrentNodePrev = nullptr;

        while (pCurrentNode != nullptr && pCurrentNode->pData->imdbScore < rating) {
            pCurrentNodePrev = pCurrentNode;
            pCurrentNode = pCurrentNode->pNext;
        }
    }

    void InsertByRating(Movie *pMovie) { // O(n)
        SearchRating(pMovie->imdbScore);

        if (pCurrentNodePrev == nullptr) {
            InsertAtFrontByRating(pMovie);
            return;
        } else {
            if (pCurrentNodePrev->pNext == nullptr) {
                InsertAtEndByRating(pMovie);
                return;
            } else {
                auto *pMovieNode = new Node<Movie>();
                pMovieNode->pData = pMovie;

                pMovieNode->pNext = pCurrentNodePrev->pNext;
                pCurrentNodePrev->pNext = pMovieNode;
            }
        }
    }

    // Rating list is maintained in ascending order, this function prints it in decending order
    void PrintListByRating(Node<Movie> *pStart) { // O(n)
        if (pStart == nullptr)
            return;

        PrintListByRating(pStart->pNext);

        cout << pStart->pData->movieTitle << " " << pStart->pData->imdbScore << endl;
    }

    void SearchDirectorsUsingGenre() { // O(n)
        string user_requested_genre;
        int choice;
        cout << " Genre Options : " << endl;
        cout << " 1. Action " << "    " << "2. Adventure " << "    " << " 3. Fantasy " << "    " << " 4.Sci-Fi "
             << "    " << " 5. Thriller " << "    " << " 6. Documentary " << "    " << endl;
        cout << " 7. Romance " << "    " << " 8. Animations " << "    " << "9. Comedy " << "    " << "10. Family "
             << "    " << " 11. Musical " << "    " << "12. Mystery " << "    " << endl;
        cout << " 13. Western " << "    " << "14. Drama " << "    " << "15. History " << "    " << "16. Sport "
             << "     " << "17. Horror " << "    " << "18. Crime " << "    " << endl;
        cout << " 19. Biography " << "    " << "20. War " << "    " << "21. Music" << "    " << "22. Game-Show"
             << "    " << "23. Reality-TV" << "    " << endl <<
             " 24. news " << "    " << "25.  Short " << endl;

        cout << " Enter the genre number for the one you are looking for: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                user_requested_genre = "Action";
                break;

            case 2:
                user_requested_genre = "Adventure";
                break;

            case 3:
                user_requested_genre = "Fantasy";
                break;

            case 4:
                user_requested_genre = "Sci-Fi";
                break;

            case 5:
                user_requested_genre = "Thriller";
                break;

            case 6:
                user_requested_genre = "Documentary";
                break;

            case 7:
                user_requested_genre = "Romance";
                break;

            case 8:
                user_requested_genre = "Animations";
                break;

            case 9:
                user_requested_genre = "Comedy";
                break;

            case 10:
                user_requested_genre = "Family";
                break;

            case 11:
                user_requested_genre = "Musical";
                break;

            case 12:
                user_requested_genre = "Mystery";
                break;

            case 13:
                user_requested_genre = "Western";
                break;

            case 14:
                user_requested_genre = "Drama";
                break;

            case 15:
                user_requested_genre = "History";
                break;

            case 16:
                user_requested_genre = "Sport";
                break;

            case 17:
                user_requested_genre = "Horror";
                break;

            case 18:
                user_requested_genre = "Crime";
                break;

            case 19:
                user_requested_genre = "Biography";
                break;

            case 20:
                user_requested_genre = "War";
                break;

            case 21:
                user_requested_genre = "Music";
                break;

            case 22:
                user_requested_genre = "Game-Show";
                break;

            case 23:
                user_requested_genre = "Reality-TV";
                break;

            case 24:
                user_requested_genre = "News";
                break;

            case 25:
                user_requested_genre = "Short";
                break;

            default: {
                cout << "Wrong Entry Entered" << endl;
                return;
            }
        }

        Node<Movie> *pMovieNode;
        pMovieNode = pStartOfSortedByYear;
        cout << endl;
        while (pMovieNode != nullptr) {
            string this_movies_genres = pMovieNode->pData->genres;

            // Our genres are stored as one whole string so this condition finds a genre within the multiple genres
            if (strstr(this_movies_genres.c_str(), user_requested_genre.c_str())) {
                if (!pMovieNode->pData->directorName.empty())
                    cout << pMovieNode->pData->directorName << " directed the movie " << pMovieNode->pData->movieTitle
                         << endl;
            }
            pMovieNode = pMovieNode->pNext;
        }
    }

    void SearchMoviesUsingGenre() { // O(n)
        string user_requested_genre;
        int choice;
        cout << " Genre Options : " << endl;
        cout << " 1. Action " << "    " << "2. Adventure " << "    " << " 3. Fantasy " << "    " << " 4.Sci-Fi "
             << "    " << " 5. Thriller " << "    " << " 6. Documentary " << "    " << endl;
        cout << " 7. Romance " << "    " << " 8. Animations " << "    " << "9. Comedy " << "    " << "10. Family "
             << "    " << " 11. Musical " << "    " << "12. Mystery " << "    " << endl;
        cout << " 13. Western " << "    " << "14. Drama " << "    " << "15. History " << "    " << "16. Sport "
             << "     " << "17. Horror " << "    " << "18. Crime " << "    " << endl;
        cout << " 19. Biography " << "    " << "20. War " << "    " << "21. Music" << "    " << "22. Game-Show"
             << "    " << "23. Reality-TV" << "    " << endl <<
             " 24. news " << "    " << "25.  Short " << endl;

        cout << " Enter the genre number for the movies you are looking up for: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                user_requested_genre = "Action";
                break;

            case 2:
                user_requested_genre = "Adventure";
                break;

            case 3:
                user_requested_genre = "Fantasy";
                break;

            case 4:
                user_requested_genre = "Sci-Fi";
                break;

            case 5:
                user_requested_genre = "Thriller";
                break;

            case 6:
                user_requested_genre = "Documentary";
                break;

            case 7:
                user_requested_genre = "Romance";
                break;

            case 8:
                user_requested_genre = "Animations";
                break;

            case 9:
                user_requested_genre = "Comedy";
                break;

            case 10:
                user_requested_genre = "Family";
                break;

            case 11:
                user_requested_genre = "Musical";
                break;

            case 12:
                user_requested_genre = "Mystery";
                break;

            case 13:
                user_requested_genre = "Western";
                break;

            case 14:
                user_requested_genre = "Drama";
                break;

            case 15:
                user_requested_genre = "History";
                break;

            case 16:
                user_requested_genre = "Sport";
                break;

            case 17:
                user_requested_genre = "Horror";
                break;

            case 18:
                user_requested_genre = "Crime";
                break;

            case 19:
                user_requested_genre = "Biography";
                break;

            case 20:
                user_requested_genre = "War";
                break;

            case 21:
                user_requested_genre = "Music";
                break;

            case 22:
                user_requested_genre = "Game-Show";
                break;

            case 23:
                user_requested_genre = "Reality-TV";
                break;

            case 24:
                user_requested_genre = "News";
                break;

            case 25:
                user_requested_genre = "Short";
                break;

            default: {
                cout << " Wrong Entry Entered" << endl;
                return;
            }
        }

        bool printRatingWise = false;
        char confirmation;
        cout << "Do you want to print them rating wise? Enter y to confirm or anything else to skip:";
        cin >> confirmation;
        confirmation == 'y' || confirmation == 'Y' ? printRatingWise = true : printRatingWise = false;

        Node<Movie> *pMovieNode;
        // If user wants to print them rating wise then do so other wise print them year wise
        printRatingWise ? pMovieNode = pStartOfSortedByRating : pMovieNode = pStartOfSortedByYear;
        cout << endl;
        while (pMovieNode != nullptr) {
            string this_movies_genres = pMovieNode->pData->genres;

            if (strstr(this_movies_genres.c_str(), user_requested_genre.c_str())) { // look for genres withing genres (string within a string)
                if (pMovieNode->pData->titleYear != -1)
                    cout << pMovieNode->pData->movieTitle << ", released in " << pMovieNode->pData->titleYear
                         << " and rated: " << pMovieNode->pData->imdbScore << endl;
                else
                    cout << pMovieNode->pData->movieTitle << ", (Release Year Unknown)"
                         << " and rated: " << pMovieNode->pData->imdbScore << endl;
            }
            pMovieNode = pMovieNode->pNext;
        }
    }
};


int main() {
    string file_path = "IMDB_Top5000.csv"; // If you are on CLion, give absolute filepath
    auto *movieList = new MovieList(file_path);

    bool quit = false;
    int action_number = 0;
    string name;
    string name2;
    int year;
    char choice;
    cout << "\t\t\t\tWelcome to IMDB (Lite)" << endl;
    cout << "Whatever action you would like to perform, enter the corresponding number." << endl;

    do {
        cout << endl;
        cout << "1. Search information of an actor." << endl;
        cout << "2. Search co-actors of an actor." << endl;
        cout << "3. Search unique co-actors of an actor." << endl;
        cout << "4. Search co-actors of co-actors of an actor." << endl;
        cout << "5. Check whether two actors are co-actors or not." << endl;
        cout << "6. Search movies directed by a director." << endl;
        cout << "7. Search directors who have directed movies of a certain genre." << endl;
        cout << "8. Search information about a movie." << endl;
        cout << "9. Search movies released in a certain year." << endl;
        cout << "10. Print all movies sorted by year (ascending or descending)." << endl;
        cout << "11. Search movies belonging to a certain genre." << endl;
        cout << "12. Print all movies sorted by rating (Descending)." << endl;
        cin >> action_number;

        // getline() is used to get a string that contains a space (cannot do that with cin)
        switch (action_number) {
            case 1:
                cout << "Enter the actor name please (case sensitive):";
                cin.ignore(); // ignore the characters in the input stream (to make getline function properly)
                getline(cin, name);
                movieList->actorList->PrintActorActedIn(name);
                break;

            case 2:
                cout << "Enter the actor name please (case sensitive):";
                cin.ignore();
                getline(cin, name);
                movieList->actorList->PrintCoActors(name);
                break;

            case 3:
                cout << "Enter the actor name please (case sensitive):";
                cin.ignore();
                getline(cin, name);
                movieList->actorList->PrintUniqueCoActors(name);
                break;

            case 4:
                cout << "Enter the actor name please (case sensitive):";
                cin.ignore();
                getline(cin, name);
                movieList->actorList->PrintUniqueCoActors(name);
                cout << endl;
                movieList->actorList->PrintCoActorsOfCoActors(name);
                break;

            case 5:
                cout << "Enter the first actor's name please (case sensitive):";
                cin.ignore();
                getline(cin, name);
                cout << "Now enter the second actor's name (case sensitive):";
                getline(cin, name2);
                cout << endl;
                movieList->actorList->areCoActors(name, name2);
                break;

            case 6:
                cout << "Enter the name of the director please (Case sensitive):";
                cin.ignore();
                getline(cin, name);
                movieList->directorList->DirectedMovies(name);
                break;

            case 7:
                movieList->SearchDirectorsUsingGenre();
                break;

            case 8:
                cout << "Enter the name of the movie please (exact for now):";
                cin.ignore();
                getline(cin, name);
                movieList->MovieDetail(name);
                break;

            case 9:
                cout << "Enter year:";
                cin >> year;
                movieList->MoviesInGivenYear(year);
                break;

            case 10:
                cout << "In ascending or descending order? Enter 'a' or 'd' respectively:";
                cin >> choice;
                if (choice == 'a' || choice == 'A')
                    movieList->PrintListByYear(true);
                else if (choice == 'd' | choice == 'D')
                    movieList->PrintListByYear(false);
                else {
                    cout << "Invalid character.\n";
                    break;
                }
                break;

            case 11:
                movieList->SearchMoviesUsingGenre();
                break;

            case 12:
                movieList->PrintListByRating(movieList->pStartOfSortedByRating);
                break;

            default:
                cout << "Invalid entry." << endl;
        }

        cout << "\nDo you want to enter another query? Enter 'y' to continue:";
        cin >> choice;
        choice == 'y' || choice == 'Y' ? quit = false : quit = true;

    } while (!quit);

    cout << "\nHave a great day!\n";
    return 0;
}

