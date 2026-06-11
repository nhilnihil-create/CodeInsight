#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

void next_combination(int n,int k,vector<int>& ret) {
    if (ret[0] == n-k) return;
    int cnt = 1,b;
    while (ret.back() == n-cnt) ret.pop_back(),cnt++;
    b = ret.back();
    ret.pop_back();
    for (int i = b+1;i < b+1+cnt;++i) ret.push_back(i);
}

int main() {
    int n,k,a[15];
    cin >> n >> k;
    vector<int> use(k);
    ll combi = 1;
    ll ans = 1e12;
    for (int i = 0;i < n;++i) cin >> a[i];
    for (int i = 0;i < n;++i) combi *= i+1;
    for (int i = 0;i < k;++i) combi /= i+1;
    for (int i = 0;i < n-k;++i) combi /= i+1;
    for (int i = 0;i < k;++i) use[i] = i;
    for (int z = 0;z < combi;++z) {
        ll ret = 0;
        int maxhight = 0;
        int j = 0;
        for (int i = 0;i < n;++i) {
            if (j < k && use[j] == i) {
                ret += max(0,maxhight+1-a[i]);
                maxhight = max(maxhight+1,a[i]);
                j++;
            }
            maxhight = max(maxhight,a[i]);
        }
        ans = min(ret,ans);
        next_combination(n,k,use);
    }
    cout << ans << endl;
    return 0;
}