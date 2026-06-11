#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    ll A, B;
    cin >> N >> A >> B;

    vector<ll> X(N);

    for(int i = 0; i < N; i++) cin >> X[i];

    ll ans = 0;

    for(int i = 1; i < N; i++) {
        ans += min(A * (X[i] - X[i - 1]), B);
    }

    cout << ans << endl;    
}