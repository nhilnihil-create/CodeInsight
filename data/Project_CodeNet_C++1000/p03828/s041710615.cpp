#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const int N = 3e6+6;
const int mod = 1e9+7;
const int inf = 1e8;
ll cnt[N];
void f(int x){
    for(int i=2;i<=x;i++){
        while(x%i==0){
            cnt[i]++;
            x/=i;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)f(i);
    ll ans = 1;
    for(int i=2;i<=n;i++){
        ans*=(cnt[i]+1);
        ans%=mod;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
