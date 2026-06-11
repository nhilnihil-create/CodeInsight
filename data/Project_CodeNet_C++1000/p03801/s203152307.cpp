#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp,cnt;
    for (int i = 0;i < n;++i) cin >> a[i];
    for (int i = 0;i < n;++i) cnt[a[i]]++;
    for (int i = n-1;i >= 0;--i) mp[a[i]] = i;
    mp[0] = 0;
    vector<ll> ans(n);
    ll sum = 0;
    for (auto it = mp.end();;) {
        if (it == mp.end()) --it;
        if (it->first == 0) break;
        int i = it->first,j = it->second;
        sum += cnt[i];
        ans[j] += sum*i;
        while ((--it)->second > j) {
            sum += cnt[it->first];
            ans[j] += cnt[it->first]*(it->first);
        }
        ans[j] -= sum*(it->first);
    }
    for (int i = 0;i < n;++i) cout << ans[i] << "\n";
    return 0;
}