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
    vector<ll> a(n),b(n);
    rep(i,0,n){
        cin>>a[i]>>b[i];
    }
    ll num=0;
    for(int i=n-1;i>=0;i--){
        a[i]+=num;
        if(a[i]%b[i]==0)continue;
        if(a[i]<=b[i])num+=b[i]-a[i];
        else{
            num +=b[i]*(a[i]/b[i]+1)-a[i];
        }
    }
    cout<<num<<endl;
    return 0;
}