#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    int ans = 0;

    int x = S[0];

    for(int i = 1; i < S.length(); i++) {
        if(S[i] != x) {
            ans++;
            x = S[i];
        }
    }

    cout << ans << endl;
}