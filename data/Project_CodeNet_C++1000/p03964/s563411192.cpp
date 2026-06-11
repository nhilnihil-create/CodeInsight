#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    ll t = 1LL, a = 1LL;

    for(int i = 0; i < N; i++) {
        ll T, A;
        cin >> T >> A;

        ll front = 1LL;
        ll back = ll(pow(10, 18)) * 2LL / max(T, A);

        ll s = pow(10, 18);

        while(front < back) {
            ll mid = front + (back - front) / 2LL;
            if(T * mid >= t && A * mid >= a) {
                s = min(s, mid);
                back = mid;
            } else {
                front = mid + 1LL;
            }
        }

        t = T * s;
        a = A * s;
    }

    cout << t + a << endl;
}