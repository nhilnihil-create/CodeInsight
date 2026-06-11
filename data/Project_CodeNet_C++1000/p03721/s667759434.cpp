#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<ll, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    vector<ll> c(pow(10, 5) + 10);

    for(int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        c[a] += b;
    }

    for(int i = 0; i < pow(10, 5) + 10; i++) {
        if(K <= c[i]) {
            cout << i << endl;
            return 0;
        }
        K -= c[i];
    }
}