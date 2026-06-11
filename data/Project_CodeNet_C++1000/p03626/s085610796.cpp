//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
//using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll n; string s1,s2; cin>>n>>s1>>s2;
    ll ans=1;
    ll cnt=0;
    if(s1[0]==s2[0])ans*=3;
    else {
        ans*=6;
        cnt++;
    }
    //cout<<ans<<endl;
    for( ll i=cnt;i<n-1;i++){
        if(s1[i]==s2[i]){
            if(s1[i+1]==s2[i+1]){
                ans*=2;
            }
            else{
                ans*=2;
                i++;
            }
        }
        else{
            if(s1[i+1]==s2[i+1]){
                ans*=1;
            }
            else{
                ans*=3;
                i++;
            }
        }
        ans%=mod;
    }
    cout<<ans<<endl;
}









