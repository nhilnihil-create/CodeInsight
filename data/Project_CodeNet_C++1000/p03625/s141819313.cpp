#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long int ll;
const int MOD=1000000007;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n+1);
    rep(i,n)cin>>a[i];
    a[n]= 0;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int l = 0,cnt=0;
    ll ans = 1;
    while(l<n-1&&cnt<2){
        if(a[l]==a[l+1]){
            cnt++;
            ans *= a[l];
            l = l + 2;
        }
        else {;l++;}
    }
    if(cnt<2)cout<<0<<endl;
    else cout<<ans<<endl;
    return 0;
}