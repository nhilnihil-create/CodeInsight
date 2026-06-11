#include <bits/stdc++.h>

using namespace std;
#define ll long long
typedef pair<ll , ll> ii;
ll n , kq[100005];
map<ll, ll> m, idx;
vector<ii> t;
int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++){
        ll foo; cin >> foo;
        m[foo]++;
        if(!idx.count(foo)) idx[foo] = i;
    }
    for(auto x = m.begin() ; x != m.end(); x++)
        t.push_back({x->first , x->second});
    sort(t.begin(), t.end());
    for(int i = t.size() - 1;i > 0;i--){
        kq[idx[t[i].first]] += (t[i].first - t[i - 1].first) * t[i].second;
        t[i - 1].second += t[i].second;
        idx[t[i - 1].first] = min(idx[t[i - 1].first] , idx[t[i].first]);
    }
    kq[idx[t[0].first]] += t[0].second * t[0].first;
    for(int i = 1;i <= n;i++) cout << kq[i] << "\n";
    return 0;
}
