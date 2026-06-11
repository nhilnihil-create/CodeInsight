#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//最大公約数(引数の型に注意)
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    return gcd(a%b,b);
}

//最小公倍数
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
 
int main() {
    int n;
    cin>>n;
    vector<ll> T(n);
    rep(i,n)cin>>T[i];
    if(n==1){
        cout<<T[0]<<endl;
        return 0;
    }
    ll ans=lcm(T[0],T[1]);
    for(int i=2;i<n;i++){
        ans=lcm(ans,T[i]);
    }
    cout<<ans<<endl;

}