#include<bits/stdc++.h>
#include<iomanip>

using namespace std;
using ll = long long;
constexpr int mod = 1e9+7;
constexpr int md = mod;
constexpr int MOD = mod;
constexpr ll inf = 1e9+5;
const int MAX=510000;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin>>n;
    vector<ll> a(n);
    map<ll,int> m;
    for(auto & b : a) cin>>b,m[b]++;
    vector<ll> v;
    v.push_back(0);
    for(int i=0;i<n;++i){
        if(a[v.back()] < a[i]) v.push_back(i);
    }
    vector<ll> ret(n);
    for(int i=v.size()-2;i>=0;i--){
        while(m.rbegin() -> first > a[v[i]]){
            auto e = *m.rbegin();
            m.erase(e.first);
            ret[v[i+1]] += 1LL*(e.first - a[v[i]])*e.second;
            m[a[v[i]]] += e.second;
        }
    }
    for(auto e : m)ret[0] += 1LL*e.first * e.second;
    for(auto r : ret) cout << r << endl;
    return 0;
}

