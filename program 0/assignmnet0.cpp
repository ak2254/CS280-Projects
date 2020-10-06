// programming assigment 0 - CS280
//CS280 Spring 2019
//Copyrighted
//Professor Gerard Ryan

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int
main(int argc, char *argv[])
{
    bool Reverse = false;
    bool Upper = false;
    bool NoVowel = false;

    for( int i=1; i<argc; i++ ) {
        string s( argv[i] );

        if( s.length() == 0 )
            continue; // skip empty strings

        // toggle by length
        if( s.length() % 2 == 0 )
            Reverse = !Reverse;
        if( s.length() % 3 == 0 )
            Upper = !Upper;
        if( s.length() % 5 == 0 )
            NoVowel = !NoVowel;

        // the only difference between fwd and reverse is loop parameters
        int startat = 0;
        int endat = s.length();
        int incr = 1;

        if( Reverse ) {
            startat = s.length() - 1;
            endat = -1;
            incr = -1;
        }

        for( int j = startat; j != endat; j += incr ) {
            char ch = s[j];
            if( NoVowel ) {
                if( ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U' )
                    continue;
            }

            if( Upper )
                ch = toupper(ch);

            cout << ch;
        }
        cout << endl;
   }

    return 0;
}
