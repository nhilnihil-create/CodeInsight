#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string O, E;
    cin >> O >> E;

    bool re = true;

    for(int i = 0; i < O.length() + E.length(); i++) {
        if(re) cout << O[i / 2];
        else cout << E[i / 2];
        re = !re;
    }

    cout << endl;
}