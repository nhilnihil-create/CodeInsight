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
    vector<string> s(3);
    vector<ll> n(3), c(3);
    rep1(i, 3){
        cin >> s[i];
        n[i] = s[i].size();
    }
    ll next = 0;
    c[0]++;
    while (c[0]<=n[0] && c[1]<=n[1] && c[2]<=n[2]){
        next = s[next][c[next]-1] - 'a';
        c[next]++;
    }
    if (c[0]>n[0]) cout << "A" << endl;
    if (c[1]>n[1]) cout << "B" << endl;
    if (c[2]>n[2]) cout << "C" << endl;
    //printf("%.12f", ans);
}