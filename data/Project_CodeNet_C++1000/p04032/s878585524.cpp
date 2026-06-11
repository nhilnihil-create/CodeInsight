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
    string s;
    bool xx,xyx;
    cin>>s;
    rep(i,s.size()-1)if(s[i]==s[i+1]){
        cout<<i+1<<" "<<i+2<<endl;
            return 0;
    }
    rep(i,s.size()-2)if(s[i]==s[i+2]){
        cout<<i+1<<" "<<i+3<<endl;
            return 0;
    }
    cout<<-1<<" "<<-1<<endl;
}
