#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,ma,mb;cin>>n>>ma>>mb;
    vin a(n),b(n),c(n);rep(i,n)cin>>a[i]>>b[i]>>c[i];
    vvin m(401,vin(401,inf));
    int k=min(n/2,18);//こうするとちょっとはやくなる
    int materiala,materialb,money;
    rep(i,1<<(n-k)){
        bitset<23> tmp(i);
        materiala=0;materialb=0;money=0;
        rep(j,n-k){
            if(tmp[j]){
                materiala+=a[k+j];
                materialb+=b[k+j];
                money+=c[k+j];
            }
        }
        m[materiala][materialb]=min(m[materiala][materialb],money);
    }
    int ans=inf;
    rep(i,1<<k){
        bitset<19> tmp(i);
        materiala=0;materialb=0;money=0;
        rep(j,k){
            if(tmp[j]){
                materiala+=a[j];
                materialb+=b[j];
                money+=c[j];
            }
        }
        for(int i=1;i*max(ma,mb)<=400;i++){
            if(i*ma<materiala||i*mb<materialb)continue;
            ans=min(ans,m[i*ma-materiala][i*mb-materialb]+money);
        }
    }
    if(ans==inf)ans=-1;
    cout<<ans<<endl;
}