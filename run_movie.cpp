using namespace std;

#include <iostream> // cin, cout, endl
#include <fstream>
#include <iterator> // back_inserter, istream_iterator
#include <sstream>  // istringstream
#include <string>   // string
#include <vector>   // vector
#include <algorithm>

// -----------
// grades_read
// -----------

void add_empty_cell(vector<string>& myVec) {
    while(myVec.size() < 6){
       myVec.insert(myVec.end(), "NA "); 
    }
}

void calc_reason(vector<string>& myVec){
    string reason = myVec[2];

    // Checking for sexuality
    if(reason.find("sex") != std::string::npos){
        myVec.insert(myVec.end(), "1 ");  
    } else {
        myVec.insert(myVec.end(), "0 "); 
    }
    
    // Checking for nudity
    if(reason.find("nud") != std::string::npos){
        myVec.insert(myVec.end(), "1 ");  
    } else {
        myVec.insert(myVec.end(), "0 "); 
    }

    // Checking for violence
    if(reason.find("viol") != std::string::npos){
        myVec.insert(myVec.end(), "1 ");  
    } else {
        myVec.insert(myVec.end(), "0 "); 
    }

    // Checking for language
    if(reason.find("lang") != std::string::npos){
        myVec.insert(myVec.end(), "1 ");  
    } else {
        myVec.insert(myVec.end(), "0 "); 
    }

    // Checking for substance
    if(reason.find("drug") != std::string::npos){
        myVec.insert(myVec.end(), "1 ");  
    } else {
        myVec.insert(myVec.end(), "0 "); 
    }

}

vector<string> movie_read (int i, ofstream& myfile) {

    // v_scores
    vector<string> movie_dat;
        string s;
        string s_next;

        // Getting title
        getline(cin, s_next);
        if(!cin){return movie_dat;}

        // read scores
        while (s_next.length() > 1 && !s_next.empty() && cin) {
            replace (s_next.begin(), s_next.end(), ',' , ' ');
            movie_dat.insert(movie_dat.end(), s_next);
            //s = s_next;
            s = s_next.c_str();
            getline(cin, s_next);
        }

        if(!cin) {
            add_empty_cell(movie_dat);
            calc_reason(movie_dat);
            return movie_dat;
        }

        string next_next;
        getline(cin, next_next);
        bool other_include = next_next.length() > 1 && !next_next.empty();
        if(other_include){

            // Checking need to insert empty cell
            if(movie_dat.size() == 4){
                movie_dat.insert(movie_dat.end(), "NA ");
            }
            replace (next_next.begin(), next_next.end(), ',' , ' ');
            // Inserting other data
            movie_dat.insert(movie_dat.end(), next_next);
            // Getting trailing newline
            getline(cin, s_next);
        } 

        add_empty_cell(movie_dat);
        calc_reason(movie_dat);
    
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
    if (headers.size() != 0){
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
}

// ----
// main
// ----

int main () {
    // Setting up file to write to
    string s;
    vector<string> headers;
    ofstream myfile("example.txt");

    // Getting all column headers
    for(int i = 0; i < 6; i++){
        getline(cin, s);
        headers.insert(headers.end(), s);
    }

    // Adding my own feature engineered columns
    headers.insert(headers.end(), "SEXUALITY ");
    headers.insert(headers.end(), "NUDITY ");
    headers.insert(headers.end(), "VIOLENCE ");
    headers.insert(headers.end(), "LANGUAGE ");
    headers.insert(headers.end(), "SUBSTANCE ");

    // Getting trailing new line
    getline(cin, s);

    // Writing header to file
    vec_to_file(myfile, headers);

    while (true) {
        // Retrieving a record
        vector<string> movie_dat = movie_read(1, myfile);
        // Writing the vector to a .csv file
        vec_to_file(myfile, movie_dat);

        // Checking end-of-file reached
        if(!cin){break;}
    }
    return 0;
}
