#include<iostream>

using namespace std;
typedef long long ll;
const ll MOD=1000000007;

ll n,m,x[100010]={0},y[100010]={0};
ll sx=0,sy=0;

signed main(){
    cin>>n>>m;
    for(int i=0;i<m+n;++i){
        if(i<n){
            cin>>x[i];
        }
        else cin>>y[i-n];
    }

    n--,m--;
    for(ll i=0;i<n;++i){
        sx+=((i+1LL)*(n-i)%MOD)*(x[i+1]-x[i]);
        if(sx>MOD)sx%=MOD;
    }
    for(ll i=0;i<m;++i){
        sy+=((i+1LL)*(m-i)%MOD)*(y[i+1]-y[i]);
        if(sy>MOD)sy%=MOD;
    }

    cout<<(sx*sy)%MOD<<endl;

    return 0;
}