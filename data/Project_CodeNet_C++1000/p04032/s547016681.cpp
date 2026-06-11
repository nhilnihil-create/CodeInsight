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
    ll n=s.size(),start,goal;

    bool cant=true;
    rep(i,n){
        if(i+1<n){
            if(s[i]==s[i+1]){
                start=i;
                goal=i+1;
                cant=false;
                break;
            }
        }
        if(i+2<n){
            if(s[i]==s[i+2]){
                start=i;
                goal=i+2;
                cant=false;
                break;
            }
        }
    }

    if(!cant) cout<<start+1<<" "<<goal+1<<endl;
    else cout<<-1<<" "<<-1<<endl;
    return 0;
}