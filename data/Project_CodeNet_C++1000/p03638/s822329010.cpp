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
const int N = 100+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
 
int a[N*N];
int G[N][N];
int main() {
    int h,w,n;
    scanf("%d%d",&h,&w);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
 
    int cnt=1;
    for(int i=1; i<=h; i++) {
        if(i%2) {
            for(int j=1; j<=w; j++) {
                if(a[cnt]==0) {
                    cnt++;
                    G[i][j]=cnt;
                    a[cnt]--;
                }
                else if(a[cnt]>0) {
                    G[i][j]=cnt;
                    a[cnt]--;
                }
            }
        }
        else {
            for(int j=w; j>=1; j--) {
                if(a[cnt]==0) {
                    cnt++;
                    G[i][j]=cnt;
                    a[cnt]--;
                }
                else if(a[cnt]>0) {
                    G[i][j]=cnt;
                    a[cnt]--;
                }
            }
        }
    }
 
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++)
            printf("%d ",G[i][j]);
        printf("\n");
    }
    return 0;
}
