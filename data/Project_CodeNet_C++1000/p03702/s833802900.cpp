
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
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
 
LL n,A,B;
LL a[N];
bool judge(LL x){
    LL temp=x*B;
    LL sub=A-B;
    LL sum=0;
    for(LL i=n;i>=1;i--){
        if(a[i]>temp){
            if((a[i]-temp)%sub)
                sum+=(a[i]-temp)/sub+1;
            else
                sum+=(a[i]-temp)/sub;
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
        scanf("%lld",&a[i]);
        right+=a[i]/B+1;
    }
    sort(a+1,a+1+n);
 
    LL left=1;
    while(left<right){
        LL mid=(left+right)>>1;
        if(judge(mid))
            right=mid;
        else
            left=mid+1;
    }
    printf("%lld\n",left);
 
    return 0;
}
