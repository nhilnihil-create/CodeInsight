#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int n,x;
    cin>>n>>x;
    ll a[n];
    rep(i,n) cin>>a[i];
    ll ans=0;
    for(int i=1;i<n;i+=2){
        if(a[i]+a[i-1]>x){
            ll y=a[i]+a[i-1]-x;
            ans+=y;
            if(y>a[i]){
                a[i]=0;
                y-=a[i];
                a[i-1]-=y;
            }
            else{
                a[i]-=y;
            }
        }
        if(i+1<n && a[i]+a[i+1]>x){
            ll y=a[i+1]+a[i]-x;
            ans+=y;
            if(y>a[i+1]){
                a[i+1]=0;
                y-=a[i+1];
                a[i]-=y;
            }
            else{
                a[i+1]-=y;
            }
        }
    }
    

    cout<<ans<<endl;
}

