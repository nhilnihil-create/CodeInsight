#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main(){
    fast_io
    
    ll n,m;
    cin>>n>>m;
    ll ans;
    if(n*2>=m){
        ans=m/2;
    }else{
        ans=n+(m-n*2)/4;
    }
    cout<<ans<<endl;

    return 0;
}