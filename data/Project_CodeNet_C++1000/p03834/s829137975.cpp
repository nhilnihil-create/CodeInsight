
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    string R= s.replace(s.find(","), 1, " ");
    R.replace(s.find(","), 1, " ");
    cout << R << endl;
   
}