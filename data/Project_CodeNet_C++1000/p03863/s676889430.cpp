#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    bool a = false, b = false;

    if(s.length() % 2 == 0) a = true;
    if(s[0] == s[s.length() - 1]) b = true;

    if(a ^ b) cout << "Second" << endl;
    else cout << "First" << endl;
}