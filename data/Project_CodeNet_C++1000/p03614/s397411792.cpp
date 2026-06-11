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
const int N = 100000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;

int a[N];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    int res=0;
    for(int i=1;i<=n-1;i++){
        if(a[i]==i){
            swap(a[i],a[i+1]);
            res++;
        }
    }
    if(a[n]==n)
        res++;
    printf("%d\n",res);

    return 0;
}