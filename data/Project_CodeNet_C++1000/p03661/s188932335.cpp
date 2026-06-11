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
const int N = 200000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
 
LL a[N];
int main() {
    LL n;
    scanf("%lld",&n);
    LL tot=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        tot+=a[i];
    }
 
    LL minn=1E15;
    LL sum=a[1];
    for(int i=2;i<=n;i++){
        LL last=tot-sum;
        LL sub=last-sum;
        sub=llabs(sub);
        minn=min(minn,sub);
        sum+=a[i];
    }
    printf("%lld\n",minn);
 
    return 0;
}