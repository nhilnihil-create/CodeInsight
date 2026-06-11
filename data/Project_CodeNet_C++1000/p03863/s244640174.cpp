#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;  cin >> s;
    ll k = s.size() - 2;

    if(s[0] == s[s.size() - 1]) k--;
    if(k % 2 == 0) cout << "Second" << endl;
    else cout << "First" << endl;

    return 0;
}
