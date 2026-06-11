#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int K, S;
    cin >> K >> S;

    int ans = 0;

    for(int i = 0; i <= K; i++) {
        for(int j = 0; j <= K; j++) {
            if(i + j <= S && S - (i + j) <= K) {
                //cerr << i << " " << j << endl;
                ans++;
            }
        }
    }

    cout << ans << endl;
}