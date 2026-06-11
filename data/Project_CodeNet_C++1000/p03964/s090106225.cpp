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
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 1000000+5;
const int dx[] = {0,0,-1,1,-1,-1,1,1};
const int dy[] = {-1,1,0,0,-1,1,-1,1};
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
 
    LL a=1,b=1;
    for(int i=1;i<=n;i++){
        LL x,y;
        scanf("%lld%lld",&x,&y);
        LL percent=max(a/x,b/y);
        while(true){
            if(percent*x>=a&&percent*y>=b)
                break;
            percent++;
        }
        a=percent*x;
        b=percent*y;
    }
    printf("%lld\n",a+b);
 
    return 0;
}