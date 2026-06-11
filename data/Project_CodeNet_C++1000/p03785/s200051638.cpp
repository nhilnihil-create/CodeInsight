//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;


int main(){
    ll n,c,k;cin>>n>>c>>k;
    vector<vector<ll>>t(n,vector<ll>(2));
    rep(i,n){
        cin>>t[i][0];
        t[i][1]=t[i][0]+k;
    }
    sort(t.begin(),t.end());
    ll l=0,r=mod;
    ll cnt=0,ans=0;
    rep(i,n){
            l=max(l,t[i][0]);r=min(r,t[i][1]);
            if(l>r){
                ans++;
                cnt=1;
                l=t[i][0];r=t[i][1];
            }
            else if(cnt==c-1){
                 ans++;
                cnt=0;
                l=0,r=mod;
            }
            else cnt++;
        }
    if(cnt!=0)ans++;
    cout<<ans<<endl;

}






