#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 1; i < s.size()-1; i++) {
        sum++;
    }
    cout << s[0] << sum << s[s.size()-1] << endl;
}