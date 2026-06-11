#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    cout << s.substr(0, 4) << " " << s.substr(4) << endl;
    return 0;
}
