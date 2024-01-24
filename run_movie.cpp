using namespace std;

#include <iostream> // cin, cout, endl
#include <fstream>
#include <iterator> // back_inserter, istream_iterator
#include <sstream>  // istringstream
#include <string>   // string
#include <vector>   // vector

// -----------
// grades_read
// -----------

vector<string> movie_read (ofstream& myfile) {
    // v_scores
    vector<string> movie_dat;
    string s;

    // Getting title
    getline(cin, s);
    getline(cin, s);

    // read scores
    while (s.length() > 1 && !s.empty()) {
        movie_dat.insert(movie_dat.end(), s);
        getline(cin, s);
    }

    return movie_dat;
}

// ------------
// grades_print
// ------------

void grades_print (const string& letter) {
    cout << letter << endl;
}

void vec_to_file(ofstream& myfile, vector<string>& headers){
    string total;
    //myfile << headers[0];
    //myfile << headers[1];
    for(string s : headers){
        //if(!s.empty()){
            total += s;
        if (!total.empty()) {
        total.erase(total.length()-1);}
        total += ", ";
        //}
        
    }
    total.erase(total.length()-2);
    myfile << total << endl;
}

// ----
// main
// ----

int main () {
    // storing column headers
    string s;
    vector<string> headers;
    ofstream myfile("example.txt");

    getline(cin, s);
    headers.insert(headers.end(), s);
    for(int i = 0; i < 5; i++){
        getline(cin, s);
        headers.insert(headers.end(), s);
    }

    vec_to_file(myfile, headers);

    // read, eval, print (REPL)
    //while (true) {
        for(int i = 0; i < 18; i++)
        {
            vector<string> movie_dat = movie_read(myfile);
        //if (!cin)
         //   break;
           // myfile << "bruh";
        //myfile << "huh";
        vec_to_file(myfile, movie_dat);
        //myfile << "bruh";
        //const string letter = grades_eval(v_v_scores);
        //grades_print(letter);
        }
        
    //}
    return 0;
}
