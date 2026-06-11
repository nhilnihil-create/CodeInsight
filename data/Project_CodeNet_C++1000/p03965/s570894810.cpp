#include "bits/stdc++.h"
#define rep(i,b) for(ll i=0;i<b;i++)
#define ll long long
using namespace std;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define debug(x) cerr<<#x<<" "<<x<<'\n';
bool cmp(pair<ll,ll> a, pair<ll,ll> b) { return a.second > b.second; }

signed main() {
    int paa=0,ans=0;
    string s;
    cin>>s;
    rep(i,s.size()){
        if(s[i]=='g'){
            if(paa>0){
                ans++;
                paa--;
            }else{
                paa++;
            }
        }else{
            if(paa>0){
                paa--;
            }else{
                paa++;
                ans--;
            }
        }
    }
    cout<<ans<<endl;
}
