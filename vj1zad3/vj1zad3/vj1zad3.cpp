#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string testString;

    getline(cin, testString);

    for (char& c : testString)
    {
        if (isalpha(c))
        {
            c = toupper(c);
        }
        if (isdigit(c))
        {
            c = '*';
        }
        else if (c == ' ' || c == '\t')
        {
            c = '_';
        }
    }

    cout << testString << endl;
}