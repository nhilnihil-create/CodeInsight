#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    if(s[0] == s[n - 1]) n++;
    if(n % 2) cout << "First" << endl;
    else cout << "Second" << endl;
}
