#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    string s; cin >> s;
    map<char,ll> ma;
    ll N=s.size();
    for(int i=0;i<N;i++){
        ma[s[i]]++;
    }
    ll ans=N*(N-1)/2+1;
    for(auto it=ma.begin();it!=ma.end();it++){
        ll res=(it->second)*(it->second-1)/2;
        ans-=res;
    }
    cout << ans << endl;
}