#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
int a[N];
LL f[N][3];
int ct[3];
int n;
int main(){
    ct[0]=ct[2]=1;
    ct[1]=-1;
    scanf("%d",&n);
    rep(i,1,n){
        if(i!=1){
            char opt[3];scanf("%s",opt);
            scanf("%d",&a[i]);if(opt[0]=='-')a[i]=-a[i];
        }
        else scanf("%d",&a[i]);
    }
    rep(i,0,n)rep(j,0,2)f[i][j]=-(1ll<<60);
    f[0][0]=0;
    rep(i,0,n){
        if(i){
            rep(j,0,2)rep(k,j,2)f[i][j]=max(f[i][j],f[i][k]);
            if(a[i]<0){
                per(j,1,0)f[i][j+1]=max(f[i][j+1],f[i][j]);
            }
        }
        rep(j,0,2){
            f[i+1][j]=max(f[i+1][j],f[i][j]+ct[j]*a[i+1]);
        }
    }
    printf("%lld\n",f[n][0]);
    return 0;
}




