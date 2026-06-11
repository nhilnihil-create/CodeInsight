#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a7=1000000007;
ll inf=1000000000000000;
#define rep(i,l,r) for(ll i=l;i<=r;i++)

ll min(ll a,ll b){
    if(a<b)return a;
    return b;
}
ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}

int main(){
    ll h,w;cin>>h>>w;
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll x,y;
    x=0;
    y=0;
    ll s[110][110];
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<a[i-1];j++){
            if(y%2==0){
                s[y][x]=i;
                if(x==w-1){
                    y++;
                }else{
                    x++;
                }
            }else{
                s[y][x]=i;
                if(x==0){
                    y++;
                }else{
                    x--;
                }
            }
        }
    }
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            if(j==0){
                cout<<s[i][j];
            }else{
                cout<<' '<<s[i][j];
            }
        }
        cout<<endl;
    }
    
    return 0;
}
