#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    cout << K * ll(pow(K - 1LL, N - 1LL)) << endl;
}