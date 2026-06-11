#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int c;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        c = count(s.begin(),s.end(),s.at(i));
        if(c>1) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}