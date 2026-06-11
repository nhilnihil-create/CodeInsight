#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
ll LCM(int a, int b){
    return a*b/gcd(a,b);
}

int main(void)
{
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,0,n)cin>>a[i];

    ll cnt1=0,cnt2=0;
    rep(i,0,n){
        if(a[i]%4==0)cnt1++;
        else if(a[i]%2==0)cnt2++;
    }
    cnt1+=cnt2/2;
    if(n/2<=cnt1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}