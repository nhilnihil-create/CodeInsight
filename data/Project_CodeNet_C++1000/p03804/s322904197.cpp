#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    rep1(i, n) cin >> a[i];
    rep1(i, m) cin >> b[i];
    ll count;
    for (ll i=0; i+m-1<(n); i++){
        for (ll j=0; j+m-1<(n); j++){
            count = 0;
            for (ll k=0; k<(m); k++){
                for (ll l=0; l<(m); l++){
                    count += (b[k][l]==a[i+k][j+l]);
                }
            }
            if (count == m*m){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    //printf("%.12f", ans);
}