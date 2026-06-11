#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
#define INF 100000000000000000
ll n,x,y,a[200005],ans;
int main(void){
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",a+i);
        if(i==0)x+=a[i];
        else y+=a[i];
    }
    ans=abs(x-y);
    for(int i=1;i<n-1;i++){
        x+=a[i];
        y-=a[i];
        ans=min(ans,abs(x-y));
    }
    printf("%lld\n",ans);
}
