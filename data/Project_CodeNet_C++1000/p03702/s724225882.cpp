#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 1000000+5;
using namespace std;
LL n,A,B;
LL h[N];
bool check(LL x){
    LL temp=x*B;
    LL sub=A-B;
    LL sum=0;
    for(LL i=n;i>=1;i--){
        if(h[i]>temp){
            if((h[i]-temp)%sub)
                sum+=(h[i]-temp)/sub+1;
            else
                sum+=(h[i]-temp)/sub;
        }
    }
    if(sum<=x)
        return true;
    return false;
}

int main() {
    scanf("%lld%lld%lld",&n,&A,&B);
    LL right=0;
    for(LL i=1;i<=n;i++){
        scanf("%lld",&h[i]);
        right+=h[i]/B+1;
    }
    sort(h+1,h+1+n);
    LL left=1;
    while(left<right){
        LL mid=(left+right)/2;
        if(check(mid))
            right=mid;
        else
            left=mid+1;
    }
    printf("%lld\n",left);
    return 0;
}
