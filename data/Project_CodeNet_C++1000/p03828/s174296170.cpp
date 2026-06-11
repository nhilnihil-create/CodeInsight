#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll N; cin>>N;
    ll k;
    map<ll,ll>mp;
    for(int i=2;i<=N;i++){
        k=i;
        for(int j=2;j<=i;j++){
            while(k%j==0){
                k/=j;
                mp[j]++;
            }
        }
    }
    ll ans=1;
    for(auto p:mp){
        ans*=p.second+1;
        ans%=mod;
    }
    cout<<ans<<endl;
}


