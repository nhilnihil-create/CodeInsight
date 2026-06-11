#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;
long long n,k,a[20],r=1ll<<60,c,t;

int main(){
    cin>>n>>k;rep(i,n)cin>>a[i];
    rep(b,1<<n){
        if (b%2==0||__builtin_popcount(b)!=k)continue;
        c=a[0]-1,t=0;
        rep(i,n){
            if (b&(1<<i)){
                if(c>=a[i])c++,t+=c-a[i];
                else c=a[i];
            }
            else c=max(c,a[i]);
        }
        r=min(r,t);
    }
    cout<<r<<'\n';
}