#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll n;cin>>n;
    ll a[100010],b[100010];
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    ll al[100010],ar[100010],bl[100010],br[100010];
    al[0]=a[0];
    ar[0]=a[0];
    bl[n-1]=b[n-1];
    br[n-1]=b[n-1];
    rep(i,1,n){
        if(a[i]>a[i-1]){
            al[i]=a[i];
            ar[i]=a[i];
        }
        else{
            al[i]=1;
            ar[i]=ar[i-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(b[i]>b[i+1]){
            bl[i]=b[i];
            br[i]=b[i];
        }
        else{
            bl[i]=1;
            br[i]=br[i+1];
        }
    }
    ll an=1;
    rep(i,0,n){
        if(al[i]>br[i]||bl[i]>ar[i])an=0;
        else{
            ll tmp=min(ar[i],br[i])-max(al[i],bl[i])+1;
            an*=tmp;
            an%=1000000007;
        }
    }
    cout<<an<<endl;
}

    







