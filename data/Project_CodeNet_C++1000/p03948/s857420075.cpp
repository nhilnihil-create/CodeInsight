#include<bits/stdc++.h>
#include<iomanip>

using namespace std;
using ll = long long;
constexpr ll mod = 1e9+7;
constexpr ll md = mod;
constexpr ll inf = 1e15;
int main(){
    ll n,t;
    cin>>n>>t;
    vector<ll> v(n);
    for(auto &a :v)cin>>a;
    vector<ll> tmp;
    ll cur = v[0];
    for(int i=1;i<n;++i){
        if(cur <= v[i])tmp.emplace_back(v[i] - cur);
        else{
            cur = v[i];
        }
    }
    sort(tmp.rbegin(),tmp.rend());
    ll num = 0;
    for(int i=0;i<(int)tmp.size();++i){
        if(tmp[i] == tmp[0])num++;
    }
    cout << num << endl;
    return 0;
}

