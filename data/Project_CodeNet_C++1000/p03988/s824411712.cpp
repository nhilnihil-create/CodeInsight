#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 12345678901234

int main(){
    ll i,j;
    ll n;
    cin>>n;
    ll M=-1;
    vector<ll> v(100,0);
    for(i=0;i<n;i++) {
        ll x;
        cin>>x;
        v[x]++;
        M=max(M,x);
    }
    ll m=100;
    for(i=0;i<=M;i++){
        ll s=max(i,M-i);
        m=min(m,s);
        v[s]--;
        if(v[s]<0){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    for(i=0;i<=m;i++){
        if(v[i]>0){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    cout<<"Possible"<<endl;


    return 0;
}