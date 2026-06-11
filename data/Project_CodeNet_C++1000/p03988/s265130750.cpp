#include<bits/stdc++.h>
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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
#define MXN 200005
/*
4+4*2+3+4
*/
int main(){
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int cnt[10005];
    for(int i = 1;i<=n;i++)
        cnt[a[i]]++;
    if(cnt[a[n]]>=2){
        for(int i=a[n];i>=(a[n]+1)/2;i--){
            if(cnt[i]==0){
                printf("Impossible\n");
                return 0;
            }
        }
        for(int  i =(a[n]-1)/2;i>=0;i--){
             if(cnt[i]){
                printf("Impossible\n");
                return 0;
            }
        }
        if(a[n]&1){
            if(cnt[a[n]/2+1]!=2){
                printf("Impossible\n");
                return 0;
            }
        }
        else{
            if(cnt[a[n]/2]!=1){
                printf("Impossible\n");
                return 0;
            }
        }
        printf("Possible\n");
        return 0;
    }
    else{
        printf("Impossible\n");
    }
}
