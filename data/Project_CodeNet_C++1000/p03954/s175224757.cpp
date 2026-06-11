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
#define MXN 200005
int cal(int *a,int n){
    int l,r;
    l=r=n/2;
    while(l>0&&r<n-1){
        if(a[l]==a[l-1])return a[l];
        if(a[r]==a[r+1])return a[r];
        l--;
        r++;
    }
    return a[0];
}
int main(){
    int n;
    scanf("%d",&n);
    int a[200005];
    n=2*n-1;
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    int Min=0,Max=n;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int aa[200005];
        for(int i = 0;i<n;i++){
            if(a[i]>mid)aa[i]=1;
            else aa[i]=0;
            //printf("%d ",aa[i]);
        }
       // printf("\n");
       // printf("%d\n",cal(aa,n));
        if(cal(aa,n)){
            Min=mid;
        }
        else{
            Max=mid;
        }
    }
    printf("%d\n",Max);
}
/*

b[i]*K!/(i)!*(K-i)!
*/