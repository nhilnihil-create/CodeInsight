#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
	ll n, m, a, b;
    string s;
	ll i, j, k;
    ll num = 0;
	ll ret = 0;
	
	cin >> n >> a >> b >> s;
    
    k = 1;
    for ( i = 0; i < n; i++ ) {
        ret = 0;
        if ( s[i] == 'a' ) {
            if ( num < a + b ) {
                num++;
                ret++;
            }
        }
        else if ( s[i] == 'b' ) {
            if ( (num < a + b) && ( k <= b) ) {
                k++;
                num++;
                ret++;
            }
        }
        cout << ((ret == 1) ? "Yes" : "No") << endl;
    }
	
	return 0;
}
