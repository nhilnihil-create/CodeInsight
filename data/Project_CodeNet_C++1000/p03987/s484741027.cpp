#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<ll,ll>;

int main() {
    ll N;
    cin >> N;
    vector<P> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end());
    set<ll> s;
    s.insert(-1);
    s.insert(N);
    ll ans =0;
    for(int i=0;i<N;i++){
        auto itr = s.upper_bound(a[i].second);
        ll right= (*itr-a[i].second);
        --itr;
        ll left= (a[i].second - *itr);
        ans += (right*left)*a[i].first;
        s.insert(a[i].second);
    }
    cout << ans << endl;
    return 0;
}