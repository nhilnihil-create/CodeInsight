#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可

const ll INF=1000000000000000000;

signed main(){
    string s;
    cin>>s;
    ll k;cin>>k;
    ll m=s.size();
    for(ll i=0;i<m;i++){
        if(s[i]=='a') continue;
        ll u=s[i]-'a';
        u=26-u;
        if(u<=k){
            s[i]='a';
            k-=u;
        }
    }
    if(k>0){
        if(s[m-1]=='a'){
            k%=26;
            s[m-1]+=k;
        }else{
            s[m-1]+=k;
        }
    }
    cout<<s<<endl;
}