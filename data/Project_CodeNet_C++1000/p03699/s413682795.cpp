#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
        ll N; cin >> N;
        vector<ll> s(N, 0);
        ll sum = 0;
        rep(i,N) {
                cin >> s[i];
                sum += s[i];
        }
        sort(s.begin(), s.end());
        bool ok = false;
        rep(i, N) {
                if (sum % 10) {
                        ok = true;
                        break;
                }
                else {
                        if (s[i] % 10) {
                                sum -= s[i];
                        }
                }
        }
        if (ok)
        cout << sum << endl;
        else
        cout << 0 << endl;





}
