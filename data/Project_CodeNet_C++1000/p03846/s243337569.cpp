#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int mod = 1e9 + 7;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> ma;
    rep(i,n) {
        cin >> a[i];
        ma[a[i]]++;
    }
    ll ans = 1;
    for(auto p : ma){
        if(p.first == 0) continue;
        if(p.second != 2) ans = 0;
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
}