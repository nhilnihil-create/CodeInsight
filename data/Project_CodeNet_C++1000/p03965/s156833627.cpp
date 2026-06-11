#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    string s;cin>>s;
    s.push_back('#');//sentinel

    ll g=0,p=0;
    ll num=1;
    rep(i,s.size()-1){
        if(s[i]==s[i+1]){
            num++;
        }else{
            if(s[i]=='g') g+=num;
            else p+=num;
            num=1;
        }
    }

    cout<<(g-p)/2<<endl;

    return 0;
}