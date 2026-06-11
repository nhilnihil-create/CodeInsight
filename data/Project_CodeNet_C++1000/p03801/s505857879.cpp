#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    ll a[100050];
    vector<ll> comp;
    comp.push_back(0);
    map<ll, ll> mini;
    map<ll, ll> number;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        comp.push_back(a[i]);
        number[a[i]]++;
        if(mini[a[i]] == 0){
            mini[a[i]] = i;
        } else {
            mini[a[i]] = min(i, mini[a[i]]);
        }
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    map<ll, ll> mp;
    map<ll, ll> ans;
    ll next = comp.back();
    ll now;
    ll added = 0;
    ll minimum = INF;
    for(int i = comp.size() - 2; i >= 0; i--){
        now = next;
        next = comp[i];
        added += number[now];
        minimum = min(minimum, mini[now]);
        ans[minimum] += added * (now - next);
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
