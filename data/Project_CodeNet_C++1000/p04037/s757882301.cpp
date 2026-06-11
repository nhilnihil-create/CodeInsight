#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
int main(){
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    a[n]=0;
    for(int i = 0;i<n;i++){
        if(a[i+1]-i-1<=0){
            int x=a[i]-i-1;
            int y=0;
            for(int j=i+1;j<n;j++){
                if(a[j]-i<=0)break;
                y++;
            }
          //  printf("%d %d %d\n",i,x,y);
            if((x&1)||(y&1)){
                printf("First\n");
            }
            else{
                printf("Second\n");
            }
            return 0;
        }
    }
}