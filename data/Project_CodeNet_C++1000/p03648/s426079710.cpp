#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define MAXN  1000005
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin>>k;
    ll e=k/50;
    ll f=k%50;
    ll rr=50+e-1;
    ll zz=rr+(f*50);
    ll xx=rr+1;
    cout<<50<<endl;
    for(ll i=0;i<=49;i++){
        xx--;
        xx=max(0LL,xx);
        if(i<f)
        cout<<(xx+50-f)<<" ";
        else cout<<xx<<" ";
    }





    return 0;
}

