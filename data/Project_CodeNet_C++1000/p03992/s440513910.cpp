#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    string s;
    cin >> s;
    cout << s.substr(0, 4) << ' ' << s.substr(4, 8) << endl;
}
