#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, A, B;
    cin >> N >> A >> B;

    vector<double> v(N);

    for(int i = 0; i < N; i++) cin >> v[i];

    sort(v.begin(), v.end(), greater<double>());

    double sum = 0;

    for(int i = 0; i < A; i++) sum += v[i];

    cout << fixed << setprecision(10) << sum / A << endl;

    double x = v[A - 1];

    ll front = 0;
    ll count = 0;

    for(int i = 0; i < N; i++) {
        if(v[i] > x) front++;
        else if(v[i] == x) count++;   
    }

    if(front == 0) {
        ll ans = 0;
        for(ll i = A; i <= min(count, B); i++) {
            ll a = 1LL;
            vector<ll> s(50);
            for(ll j = count; j > i; j--) {
                ll n = j;
                for(ll k = 2LL; k * k <= n; k++) {
                    while(n % k == 0) {
                        s[k]++;
                        n /= k;
                    }
                }
                if(n != 0) s[n]++;
            }
            for(ll j = count - i; j > 1LL; j--) {
                ll n = j;
                for(ll k = 2LL; k * k <= n; k++) {
                    while(n % k == 0) {
                        s[k]--;
                        n /= k;
                    }
                }
                if(n != 0) s[n]--;
            }
            for(ll j = 0; j < 50; j++) {
                for(ll k = 0; k < s[j]; k++) {
                    a *= j;
                }
            }
            cerr << a << endl;
            ans += a;
        }
        cout << ans << endl;
    } else {
        ll ans = 1;
        vector<ll> s(50);
        for(ll j = count; j > A - front; j--) {
            ll n = j;
            for(ll k = 2LL; k * k <= n; k++) {
                while(n % k == 0) {
                    s[k]++;
                    n /= k;
                }
            }
            if(n != 0) s[n]++;
        }
        for(ll j = count - (A - front); j > 1LL; j--) {
            ll n = j;
            for(ll k = 2LL; k * k <= n; k++) {
                while(n % k == 0) {
                    s[k]--;
                    n /= k;
                }
            }
            if(n != 0) s[n]--;
        }
        for(ll j = 0; j < 50; j++) {
            for(ll k = 0; k < s[j]; k++) {
                ans *= j;
            }
        }
        cout << ans << endl;
    }
}