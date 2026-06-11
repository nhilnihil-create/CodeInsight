#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main(){
    ll h,w;cin>>h>>w;
    string a[h];rep(i,0,h-1)cin>>a[i];
    string alp="qwertyuiopasdfghjklzxcvbnm";
    sort(alp.begin(),alp.end());
    ll c[26];rep(i,0,25)c[i]=0;
    rep(i,0,h-1){
        rep(j,0,w-1){
            rep(k,0,25){
                if(a[i][j]==alp[k]){
                    c[k]++;
                    break;
                }
            }
        }
    }
    ll ok1,ok2;
    if(h%2==1 && w%2==1){
        ok1=1;
        ok2=(h-1)/2+(w-1)/2;
    }else if(h%2==0 && w%2==0){
        ok1=0;
        ok2=0;
    }else if(h%2==0 && w%2==1){
        ok1=0;
        ok2=h/2;
    }else{
        ok1=0;
        ok2=w/2;
    }
    rep(i,0,25){
        if(c[i]%4==0){
            continue;
        }else if(c[i]%4==2){
            ok2--;
            if(ok2<0){
                cout<<"No"<<endl;
                return 0;
            }
        }else{
            ok1--;
            if(ok1<0){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    
    return 0;
}

