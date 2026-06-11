#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for(int i = 0; i < 4; i++) {
        cout << s[i];
    }
    cout << " ";
    for(int i = 4; i < 12; i++) {
        cout << s[i];
    }
    cout << endl;

    return 0;
}