#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;
typedef pair<ll,ll> P;


int main(){
    ll n;cin>>n;
    ll a[100010],b[100010];
    map<ll,ll> bcn;
    rep(i,0,n){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    rep(i,0,n){
        bcn[b[i]]=i;
    }
    ll an=0;
    rep(i,0,n){
        ll tmp=bcn[a[i]];
        if((i+tmp)%2==1)an++;
    }
    cout<<an/2<<endl;
}

    







