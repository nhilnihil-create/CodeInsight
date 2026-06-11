#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
 
int main() {
    string A; cin >> A;
   	ll n = A.size();
  	vector<ll> cnt(26);
    ll ans = 0;
 
    rep(i, A.size()) cnt.at(A.at(i)-'a')++;
 
    rep(i, 26) {
        ll x = cnt.at(i);
        ans += x*(x-1)/2;
    }
 
    cout << n*(n-1)/2 - ans + 1 << endl;
}