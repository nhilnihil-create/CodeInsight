#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
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
ll inf=(ll)1E18;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int main(){fastio
    ll n;cin>>n;
    ll a[3*n+1];rep(i,1,3*n)cin>>a[i];
    ll b[3*n+1];rep(i,1,3*n)b[i]=a[3*n+1-i];
    ll dp[3*n+1],ep[3*n+1];
    
    ll sum=0;
    multiset<ll> st;
    rep(i,1,n){
        sum+=a[i];
        st.insert(a[i]);
    }
    dp[n]=sum;
    rep(i,n+1,n*2){
        if((ll)*st.begin()<a[i]){
            sum-=*st.begin();
            st.erase(st.begin());
            sum+=a[i];
            st.insert(a[i]);
            dp[i]=sum;
        }else{
            dp[i]=sum;
        }
    }
    
    sum=0;
    st.clear();
    rep(i,1,n){
        sum+=b[i];
        st.insert(b[i]);
    }
    ep[n]=sum;
    rep(i,n+1,n*2){
        auto itr=st.end();
        --itr;
        if((ll)*itr>b[i]){
            sum-=*itr;
            st.erase(itr);
            sum+=b[i];
            st.insert(b[i]);
            ep[i]=sum;
        }else{
            ep[i]=sum;
        }
    }
    ll maxi=-inf;
    rep(i,n,n*2){
        maxi=max(maxi,dp[i]-ep[3*n-i]);
    }
    /*
    rep(i,n,n*2){
        cout<<dp[i]<<' '<<ep[i]<<endl;
    }*/
    cout<<maxi<<endl;
    
    return 0;
}



