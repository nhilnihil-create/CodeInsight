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
const int N = 100000+5;
const int dx[] = {0,0,-1,1,-1,-1,1,1};
const int dy[] = {-1,1,0,0,-1,1,-1,1};
using namespace std;

int sum[N];
int main() {
    for(int i=1; i<=N-1; i++)
        sum[i]=sum[i-1]+i;

    int x;
    scanf("%d",&x);
    int left=1,right=N-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(sum[mid]<x){
            left=mid+1;
        }
        else if(sum[mid]>=x){
            right=mid-1;
        }
    }
    int pos=right+1;
    printf("%d\n",pos);
    return 0;
}
