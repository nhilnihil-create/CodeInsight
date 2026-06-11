#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    str.insert(str.begin() + 4, ' ');
    cout << str << endl;
    return 0;
}
