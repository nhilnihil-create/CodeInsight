#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i,n) for(ll i=0;i<(int)(n);i++)
#define REP(i,m,n) for(ll i=m;i<(int)(n);i++)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<ll,ll> pint;
const long long INF = 1LL<<60;
const ll MOD = 1000000007;
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
int main(){
    ll n;cin>>n;
    vector<ll> T(n);rep(i,n)cin>>T[i];
    vector<ll> A(n);rep(i,n)cin>>A[i];
    vector<ll> tamin(n,0);
    vector<ll> ans(n,0);
    bool flag=false;
    tamin[0]=T[0];
    rep(i,n-1){
        if(flag)break;
        if(T[i]!=T[i+1]){
            tamin[i+1]=T[i+1];
            if(A[i]<T[i+1]){
                flag=true;
                cout<<0<<endl;
                break;
            }
        }
    }
    if(tamin.back()!=0&&tamin.back()!=A.back()){
        cout<<0<<endl;
        flag=true;
    }
    else if(tamin.back()==0){
        tamin[n-1]=A[n-1];
    }
    rep(i,n-1){
        if(flag) break;
        ll m = n-1-i;
        if(A[m]!=A[m-1]){
            if(tamin[m-1]==0){
                tamin[m-1]=A[m-1];
                if(A[m-1]>T[m-1]){
                    flag=true;
                    cout<<0<<endl;
                    break;
                }
            }
            else if(A[m-1]!=tamin[m-1]){
                cout<<0<<endl;
                flag=true;
            }
        }
    }
    if(! flag){
        ll res=1;
        rep(i,n){
            //cout<<tamin[i];
            if(tamin[i]==0){
                res*=min(T[i],A[i])%MOD;
                res%=MOD;
            }
        }
        cout<<res%MOD<<endl;
    }
}
