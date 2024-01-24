using namespace std;

#include <iostream> // cin, cout, endl
#include <iterator> // back_inserter, istream_iterator
#include <sstream>  // istringstream
#include <string>   // string
#include <vector>   // vector

// -----------
// grades_read
// -----------

vector<string> movie_read () {
    // v_scores
    vector<string> movie_dat(5);

    // Getting title
    getline(cin, s);

    // read scores
    while (s != NULL) {
        istringstream iss(s);
        copy(istream_iterator<int>(iss), istream_iterator<int>(), back_inserter(movie_dat));
        getline(cin, s);
    }

    // Removing extra blank line
    getline(cin, s);

    print movie_dat;
    return movie_dat;
}

// ------------
// grades_print
// ------------

void grades_print (const string& letter) {
    cout << letter << endl;
}

// ----
// main
// ----

int main () {
    // throwing out column headers
    string s;
    getline(cin, s);
    getline(cin, s);
    getline(cin, s);
    getline(cin, s);
    getline(cin, s);
    getline(cin, s);

    // read, eval, print (REPL)
    while (true) {
        const vector<string> movie_dat = movie_read();
        if (!cin)
            break;
        //const string letter = grades_eval(v_v_scores);
        //grades_print(letter);
    }
    return 0;
}
