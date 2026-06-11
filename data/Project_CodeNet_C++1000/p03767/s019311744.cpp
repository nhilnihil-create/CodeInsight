#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)
#define INF (1<<18)


int main() {
    int n;
    cin >> n;
    vector<int> a;
    rep(i,3*n){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end(), greater<>());

    ll ans = 0;
    rep(i,n){
        ans += a[2*i+1];
    }

    cout << ans << endl;

    return 0;
}