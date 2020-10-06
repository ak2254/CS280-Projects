// programming assigment 1 - CS280
//CS280 Spring 2019
//Copyrighted
//Professor Gerard Ryan




#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <map>
using namespace std;

int main( int argc, char* argv[] )
{
    bool debug = false;

    map<string,string> subs;
    int nsubs = 0;
    string inLine;

    if( argc != 3 ) {
        cout << "TWO FILENAMES REQUIRED" << endl;
        return 1;
    }

    ifstream subFile( argv[1] );
    if( !subFile.is_open() ) {
        cout << "BAD FILENAME " << argv[1] << endl;
        return 1;
    }

    // process substitutions file
    bool inWord = false;
    string currentWord;
    int nWords = 0;
    string word[2];
    char ch;
    while( subFile.get(ch) ) {
        if( isspace(ch) ) {
            if( inWord ) {
                // if I see a space while I am in a word, then the word is done!
                inWord = false;
                if( nWords < 2 ) {
                    // strip leading and trailing punctuation
                    int firstAt, lastAt;
                    for( firstAt = 0; firstAt < currentWord.length(); firstAt++ )
                         if( !ispunct(currentWord[firstAt]) )
                             break;

                    if( firstAt != currentWord.length() ) {
                        // first letter is at firstAt; now delete trailing
                        for( lastAt = currentWord.length() - 1; lastAt > firstAt; lastAt-- )
                            if( !ispunct(currentWord[lastAt]) )
                                break;

                        currentWord = currentWord.substr(firstAt, lastAt-firstAt+1);

                        word[ nWords++ ] = currentWord;
                    }
                }
                else nWords++;

                currentWord.clear(); // get ready for the next one
            }
            if( ch == '\n' ) {
                 if( nWords == 2 ) {
                     subs[ word[0] ] = word[1];
                 }
                 // else just ignoring the line

                 nWords = 0;
             }
        }
        else {
            inWord = true;

            // save everything in lowercase
            ch = tolower(ch);
            currentWord += ch;
        }
    }

    subFile.close();

    if( debug )
        for( const auto& sp : subs )
            cout << sp.first << ":" << sp.second << endl;

    ifstream wFile( argv[2] );
    if( !wFile.is_open() ) {
        cout << "BAD FILENAME " << argv[2] << endl;
        return 1;
    }

    inWord = false;
    currentWord.clear();

    string leadp, trailp, testword;

    while( wFile.get(ch) ) {
        if( isspace(ch) ) {
            if( inWord ) {
                // if I see a space while I am in a word, then the word is done!
                inWord = false;

                // process currentWord
                int i, fcp, lcp; /* fcp is First Char Position... lcp is Last Char Position */
                for( i = 0; i < currentWord.length() && ispunct( currentWord[i] ); i++ )
                    leadp += currentWord[i];
                fcp = i;
                for( lcp = currentWord.length() - 1; lcp > fcp; lcp-- )
                    if( !ispunct( currentWord[lcp] ) )
                        break;
                trailp = currentWord.substr(lcp+1);
                for( i = fcp; i <= lcp; i++ )
                    testword += (char)tolower( currentWord[i] );

                const auto& sub = subs.find(testword);
                if( sub != subs.end() ) {
                    nsubs++;

                    cout << leadp;
                    string newWord = sub->second;

                    if( isupper( currentWord[fcp] ) ) {
                        newWord[0] = toupper( newWord[0] );
                    }
                    cout << newWord;

                    cout << trailp;
                }
                else {
                    cout << currentWord;
                }

                currentWord.clear(); // get ready for the next one
                leadp.clear();
                trailp.clear();
                testword.clear();
            }
            cout << ch; // print the space
        }
        else {
            inWord = true;
            currentWord += ch;
        }
    }

    wFile.close();
    if( nsubs > 0 )
        cout << "NUMBER OF CHANGES: " << nsubs << endl;

    return 0;
}