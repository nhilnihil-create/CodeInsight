#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    int n,k,x,y;cin>>n>>k>>x>>y;
    if(k>=n)cout<<n*x<<endl;
    else cout<<k*x+(n-k)*y<<endl;
}
