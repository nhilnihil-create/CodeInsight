#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;
map <int, int> cnt, mn;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    for(int i = 0 ; i < n ; i++){
        cnt[a[i]]++;
        if(mn.count(a[i]) == 0){
            mn[a[i]] = i;
        }
        mn[a[i]] = min(mn[a[i]], i);
    }
    sort(a.rbegin(), a.rend());
    a.erase(unique(a.begin(), a.end()), a.end());
    a.push_back(0);
    vector <ll> ans(n);
    n = a.size();
    int cur_idx = 1e9;
    int cur_cnt = 0;
    for(int i = 0 ; i + 1 < n ; i++){
        cur_idx = min(cur_idx, mn[a[i]]);
        cur_cnt += cnt[a[i]];
        ans[cur_idx] += 1LL * (a[i] - a[i + 1]) * cur_cnt;
        
    }
    for(auto &i : ans) cout << i << "\n";
}
