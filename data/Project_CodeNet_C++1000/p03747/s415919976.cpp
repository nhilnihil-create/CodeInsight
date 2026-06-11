#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;






int main(){
    ll n,l,t;
    cin>>n>>l>>t;
    vector<pll> a(n);
    ll cnt=0;
    for(auto &i:a){
        cin>>i.F>>i.S;
        if(i.S!=a[0].S){
            ll dist;
            if(a[0].S==1){
                dist=i.F-a[0].F;
            }
            else{
                dist=a[0].F+l-i.F;
            }
            ll move=2*t;
            if(dist<=move){move-=dist; cnt++; cnt+=move/l;}
        }
    }
    cnt%=n;
    if(a[0].S==2){
        cnt=n-cnt;
        cnt%=n;
        vector<pll> W(n);
        for(int i=0;i<n;i++){
            W[i].S=i;
            if(a[i].S==1){
                W[i].F=(a[i].F+t)%l;
            }
            else{
                W[i].F=(a[i].F-t)%l;
                if(W[i].F<0){W[i].F+=l;}
            }
        }
        sort(W.begin(),W.end());
        ll s=-1;
        for(int i=0;i<n;i++){
            if(W[i].S==0){s=(i-cnt+n)%n;}
        }
        for(ll i=s;i<n;i++){
            cout<<W[i].F<<endl;
        }
        for(ll i=0;i<s;i++){
            cout<<W[i].F<<endl;
        }
    }
    else{
        vector<pll> W(n);
        for(int i=0;i<n;i++){
            W[i].S=n-i;
            if(a[i].S==1){
                W[i].F=(a[i].F+t)%l;
            }
            else{
                W[i].F=(a[i].F-t)%l;
                if(W[i].F<0){W[i].F+=l;}
            }
        }
        sort(W.begin(),W.end());
        ll s=-1;
        for(int i=0;i<n;i++){
            if(W[i].S==n){s=(i-cnt+n)%n;}
        }
        for(ll i=s;i<n;i++){
            cout<<W[i].F<<endl;
        }
        for(ll i=0;i<s;i++){
            cout<<W[i].F<<endl;
        }
    }
    
    
    return 0;
}
