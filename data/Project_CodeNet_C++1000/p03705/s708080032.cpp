#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,a,b;
    scanf("%lld%lld%lld",&n,&a,&b);
    ll ans =1+(n-2)*(b-a);
    if(ans<=0)ans=0;
    printf("%lld\n",ans);
}