#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n, x;
vector <int> a;

ll calc(int k){
    multiset <int> s;
    for(int i = n - k ; i < n ; i++){
        s.insert(a[i]);
    }
    ll ret = 0;
    for(int i = 0 ; i < n ; i++){
        s.insert(a[i]);
        s.erase(s.find(a[(i - k + n) % n]));
        ret += *s.begin();
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    a.resize(n);
    for(auto &i : a) cin >> i;
    ll ans = 1e18;
    for(int i = 0 ; i < n ; i++){
        ans = min(ans, calc(i + 1) + 1LL * i * x);
    }
    cout << ans << endl;
}
