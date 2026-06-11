#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 1LL<<60
#define pi 3.14159265358979323846
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    ll n;cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll ans=0;
    for(ll i=0;i<n-1;i++){
        if(a[i]%2==1 && a[i+1]>0){
            a[i]--;
            a[i+1]--;
            ans++;
        }
    }
    
    for(ll i=0;i<n;i++){
        ans+=(a[i]/2);
    }

    cout<<ans<<endl;
    return 0;
}