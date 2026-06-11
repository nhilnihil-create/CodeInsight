#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
const int maxn=1e5+10;
int a[maxn],n;
int main(){
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    rep(i,1,n) if(a[i+1]<i+1){
        int ans=(a[i]-i)&1,j=i;
        while(j<n&&a[j+1]==i) ++j;
        ans|=(j-i)&1;puts(ans?"First":"Second");break;
    }
    return 0;
}