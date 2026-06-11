#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    ll ans =  0;
    rep(i,n-1){
        if(a[i]+a[i+1]>x){
            ans += a[i]+a[i+1]-x;
            if(a[i]+a[i+1]-x>a[i+1]){
                a[i+1]=0;
            }else {
                a[i+1]=a[i+1]-(a[i]+a[i+1]-x);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}