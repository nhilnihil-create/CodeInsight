#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<l_l> vpl;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=1;i<=(n);i++)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=10100100100100100;
template<class T> inline bool chmin(T& a,T b){
if(a>b){
a=b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a,T b){
if(a<b){
a=b;
return true;
}
return false;
}
ll a[100100];
ll n;
int main(){
    cin>>n;
    ll nowmin=n+1;
    ll sum=0;
    vl ans(n+1);
    map<ll,ll> mp,id;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
        if(id.find(a[i])==id.end())id[a[i]]=i;
    }
    mp[0]++;
    for(auto it=--mp.end();;it--){
        if(it==mp.begin())break;
        nowmin=min(nowmin,id[it->fi]);
        sum+=it->se;
        it--;
        ll last=it->fi;
        it++;
        ans[nowmin]+=1ll*(it->fi-last)*sum;
        //cout<<it->fi<< " "<<it->se<<endl;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
    return 0;
}