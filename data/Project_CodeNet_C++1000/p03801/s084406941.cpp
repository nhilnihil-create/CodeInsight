#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    map<int, int> mp;
    rep(i, n)mp[a[i]]++;
    vector<P> b;
    for(auto p : mp){
        b.push_back(p);
    }
    for(int i = b.size()-1; i > 0; i--){
        b[i-1].second += b[i].second;
    }

    vector<ll> ans(n, 0);
    ll pre = 0;
    int idx = 0;
    rep(i, n){
        if(idx < b.size()){
            while(b[idx].first <= a[i]){
                ll d = b[idx].first - pre;
                ans[i] += d * b[idx].second;
                pre = b[idx].first;
                idx++;
                if(idx == b.size())break;
            }
        }
    }
    
    rep(i, n)cout << ans[i] << endl;
}