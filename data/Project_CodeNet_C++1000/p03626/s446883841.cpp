#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string S1, S2;
    cin >> N >> S1 >> S2;

    ll mod = pow(10, 9) + 7;

    vector<ll> x;

    for(int i = 0; i < N; i++) {
        if(S1[i] == S2[i])
            x.push_back(1LL);
        else {
            x.push_back(2LL);
            i++;
        }
    }

    vector<ll> a;

    a.push_back(x[0] * 3LL);

    for(int i = 0; i < x.size() - 1; i++) {
        if(x[i] == 1) {
            a.push_back(2LL);
        } else {
            if(x[i + 1] == 1) {
                a.push_back(1LL);
            } else {
                a.push_back(3LL);
            }
        }
    }

    ll ans = 1LL;

    for(int i = 0; i < a.size(); i++) {
        ans *= a[i] % mod;
        ans %= mod;
    }

    cout << ans << endl;
}