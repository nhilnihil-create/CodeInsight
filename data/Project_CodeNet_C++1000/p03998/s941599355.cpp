#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    vector<string> s(3);
    vector<int> p(3);

    for(int i = 0; i < 3; i++) cin >> s[i];

    int t = 0;

    while(true) {
        if(p[t] == s[t].length()) {
            cout << char('A' + t) << endl;
            return 0;
        }
        int x = s[t][p[t]] - 'a';
        p[t]++;
        t = x;
    }
}