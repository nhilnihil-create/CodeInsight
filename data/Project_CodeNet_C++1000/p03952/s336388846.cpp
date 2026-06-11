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
    ll n,x;cin>>n>>x;
    if(x==1 || x==2*n-1){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        ll a[2*n-1];rep(i,0,2*n-2)a[i]=0;
        bool b[2*n];rep(i,1,2*n-1)b[i]=true;
        a[n-1]=x;b[x]=false;
        if(n==2){
            a[0]=1;b[1]=false;a[2]=3;b[3]=false;
        }else{
            if(x==2){
                a[n-2]=1;b[1]=false;
                a[n-3]=x+1;b[x+1]=false;
                a[n]=x+2;b[x+2]=false;
            }else{
                a[n-2]=x+1;b[x+1]=false;
                a[n-3]=1;b[1]=false;
                a[n]=2;b[2]=false;
            }
        }
        ll j=1;
        rep(i,0,2*n-2){
            while(!b[j]){
                j++;
                if(j==2*n)break;
            }
            if(j==2*n)break;
            if(a[i]==0){
                a[i]=j;
                j++;
            }
        }
        rep(i,0,2*n-2){
            cout<<a[i]<<endl;
        }
        
    }
    
    
    return 0;
}

