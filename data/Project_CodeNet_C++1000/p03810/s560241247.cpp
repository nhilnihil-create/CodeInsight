#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>
 
using namespace :: std;
 
const ll maxn=1e5+3100;
const ll mod=1e9+7;
const ll inf=1e9+500;
 
ll a[maxn];
 
int main(){
    ll n;
    cin>>n;
    if(n>1){
        ll ans=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        bool dor=0;
        while(1){
            ll ans=0;
            for(ll i=1;i<=n;i++){
                ans+=a[i]-1;
            }
            if(ans%2==1){
                if(dor==0){
                    cout<<"First\n";
                }else{
                    cout<<"Second\n";
                }
                return 0;
            }
            ll dd=0;
            for(ll i=1;i<=n;i++){
                if(a[i]%2==1 && dd==0 && a[i]>1){
                    dd=1;
                    a[i]--;
                }
            }
            ll gc=a[1];
            for(ll i=2;i<=n;i++){
                gc=__gcd(gc,a[i]);
            }
            if(gc%2==1){
                if(dor==0){
                    cout<<"Second\n";
                }else{
                    cout<<"First\n";
                }
                return 0;
            }
            for(ll i=1;i<=n;i++){
                a[i]/=gc;
            }
            dor=!dor;
        }
    }
    if(n==1){
        cout<<"Second";
        return 0;
    }
}