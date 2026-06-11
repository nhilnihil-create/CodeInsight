#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int x = 0;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'p') x++;
    }

    cout << s.length() / 2 - x << endl;
}