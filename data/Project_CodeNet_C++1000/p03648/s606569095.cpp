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
    LL k;
    scanf("%lld",&k);
    if(k==0){
        printf("2\n");
        printf("1 1\n");
    }
    else{
        for(int i=1;i<=50;i++)
            a[i]=i-1;

        LL temp=(k-1)/50+1;
        for(int i=1;i<=50;i++)
            a[i]+=(temp-1);

        int times=k%50;
        if(times==0)
            for(int i=1;i<=50;i++)
                a[i]++;

        for(int i=1;i<=times;i++){
            for(int j=1;j<=50;j++){
                if(i==j)
                    a[i]+=50;
                else
                    a[j]--;
            }
        }

        printf("%d\n",50);
        for(int i = 1;i<=50;i++)
            printf("%lld ",a[i]);
        printf("\n");
    }
    return 0;
}
