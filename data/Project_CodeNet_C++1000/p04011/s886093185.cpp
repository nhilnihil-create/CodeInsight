#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K, X, Y;
    cin >> N >> K >> X >> Y;

    ll ans = N * Y + (X - Y) * min(N, K);

    cout << ans << endl;
}