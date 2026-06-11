#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

void solve() {
    ll n; cin >> n;
    ll odd = 0;
    rep(i, 0, n){
        ll a; cin >> a;
        if(a%2 != 0) odd++;
    }
    if(odd%2 != 0) puts("NO");
    else puts("YES");
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
