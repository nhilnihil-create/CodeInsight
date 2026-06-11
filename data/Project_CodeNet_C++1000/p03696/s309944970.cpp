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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll add_l = 0, add_r = 0;
    ll sum = 0;
    rep1(i, n){
        if (s[i]==')') sum++;
        else sum--;
        add_l = max(add_l, sum);
    }
    sum = 0;
    rep1(i, n){
        if (s[n-1-i]=='(') sum++;
        else sum--;
        add_r = max(add_r, sum);
    }
    rep1(i, add_l) cout << '(';
    cout << s;
    rep1(i, add_r) cout << ')';
    cout << endl;
    //printf("%.12f", ans);
}