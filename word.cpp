#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//This code will read a file and allow the user to type a word to see the number of occurences of that
//word in the file. One may also type totalWords to view the total number of words in the file.


int main()
{

    ifstream in_file("text.txt");
    ofstream out_file("text1.txt");
    
    istream_iterator< string > is( in_file );
    istream_iterator< string > eof;

    vector<string> text;
    vector<string> textCount;
    copy( is, eof, back_inserter( text ));

    
    unordered_map<string,int> map;
    for(vector<string>::iterator it = text.begin(); it != text.end(); it++)
    {
        map[*it]++; map["totalWords"]++;
    }
    
    for(unordered_map<string,int>::iterator it = map.begin(); it != map.end(); it++)
    {
        textCount.push_back((*it).first + " " + to_string(map[(*it).first]));
    }

    ostream_iterator<string> os( out_file, " " );
    copy( textCount.begin(), textCount.end(), os );
    
    string word;
    cout << "enter a word to see how many occurences there are or enter totalWords to see the total number of words ";
    cin >> word;
    cout << map[word];
    
}
