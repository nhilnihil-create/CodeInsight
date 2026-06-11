#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1000000007;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    ll c = 0;
    ll ans = 1;
    bool pat = true;
    while (c<n){
        if (c==0){
            if (s[c]==t[c]){
                ans *= 3;
                pat = false;
                c++;
            }
            else{
                ans *= 6;
                pat = true;
                c += 2;
            }
        }
        else if (pat){
            if (s[c]==t[c]){
                ans *= 1;
                pat = false;
                c++;
            }
            else{
                ans *= 3;
                pat = true;
                c += 2;
            }
        }
        else{
            if (s[c]==t[c]){
                ans *= 2;
                pat = false;
                c++;
            }
            else{
                ans *= 2;
                pat = true;
                c += 2;
            }
        }
        ans %= MOD;
    }
    cout << ans << endl;
    //printf("%.12f", ans);
}