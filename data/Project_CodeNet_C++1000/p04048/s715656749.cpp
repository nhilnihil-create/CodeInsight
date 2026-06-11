#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define ll long long
ll solve(ll a,ll b){
    if (!a) return 0;
    ll res=a*(b/a)*2;
    return b%a?res+solve(b%a,a):res-a;
}
ll n,x,ans;
int main(){
    scanf("%lld%lld",&n,&x);
    ans=n+solve(min(x,n-x),max(x,n-x));
    printf("%lld\n",ans);
    return 0;
}