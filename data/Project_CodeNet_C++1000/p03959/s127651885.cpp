#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>
//#include <bits/stdc++.h>
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
using namespace std;
#define ALL(X) X.begin(),X.end()
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=2147483647;
const ll LLMAX=9223372036854775807;

ll modadd(ll a,ll b,ll mod=MOD){
    return (a%mod+b%mod)%mod;
}

ll modsub(ll a,ll b,ll mod=MOD){
    a%=mod;
    b%=mod;
    if(a>=b) return a-b;
    else return mod-b+a;
}

ll modmul(ll a,ll b,ll mod=MOD){
    return ((a%mod)*(b%mod))%mod;
}

ll modpow(ll a, ll n,ll mod=MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll moddiv(ll a,ll b,ll mod=MOD) {
    return modmul(a, modpow(b, mod-2));
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    cin>>N;
    vll T(N),A(N);
    for(ll i=0;i<N;i++)cin>>T[i];
    for(ll i=0;i<N;i++)cin>>A[i];
    
    vvll h(N,vll(2));
    for(ll i=0;i<N;i++){
        h[i][0]=1;
        h[i][1]=LLMAX;
    }
    
    for(ll i=0;i<N;i++){
        if(i==0){
            h[0][0]=T[0];
            h[0][1]=T[0];
        }else{
            if(T[i]==T[i-1]){
                h[i][0]=1;
                h[i][1]=T[i];
            }else{
                h[i][0]=T[i];
                h[i][1]=T[i];
            }
        }
    }
    
    for(ll i=N-1;i>=0;i--){
        if(i==N-1){
            if(h[i][0]>A[i]||h[i][1]<A[i]){
                cout<<0<<endl;
                return 0;
            }
            h[i][0]=A[i];
            h[i][1]=A[i];
        }else{
            if(A[i]==A[i+1]){
                if(h[i][0]>A[i]){
                    cout<<0<<endl;
                    return 0;
                }
                h[i][1]=min(A[i],h[i][1]);
            }else{
                if(h[i][0]>A[i]||h[i][1]<A[i]){
                    cout<<0<<endl;
                    return 0;
                }
                h[i][0]=A[i];
                h[i][1]=A[i];
            }
        }
    }
    
    ll ans=1;
    for(ll i=0;i<N;i++){
        if(h[i][1]-h[i][0]+1<=0){
            cout<<0<<endl;
            return 0;
        }
        ans=modmul(ans,h[i][1]-h[i][0]+1);
    }
    cout<<ans<<endl;
    
    return 0;
}
