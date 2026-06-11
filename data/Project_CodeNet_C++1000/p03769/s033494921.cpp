#include<cstdio>
#include<cstring>
#include<algorithm>

#define ll long long
#define inf 10000000000000ll

using namespace std;

int N,A[10010],nm[210];
ll f[210],c[210][210],n;

int main()
{
    f[0]=f[1]=0;
    for (int i=2;i<=50;i++){
        f[i]=(1ll<<i-1)-1;
    }
    for (int i=0;i<=50;i++){
        c[i][0]=1;
        for (int j=1;j<=i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    scanf("%lld",&n);
    
    for (int i=1;i<=100&&n;i++){
        nm[i]=0;
        ll mx=0;int p=0;
        for (int w=1;w<=50;w++)if(f[w]<=n){
            if (mx<f[w]) mx=f[w],nm[i]=w,p=0;
            
            for (int j=nm[i-1]/2;j>=1;j--){
                ll nw=0;
                for (int k=1;k<=j;k++) nw=min(inf,nw+c[j][k]*c[nm[i-1]-j][k]);
                nw*=min((inf+nw-1)/nw,(ll)w-1);
                if (nw+f[w]>n) continue;
                if (mx<nw+f[w]) mx=nw+f[w],nm[i]=w,p=j;
            }
        }

        n-=mx;
        for (int j=1;j<=p;j++) A[N-j+2]=A[N-j+1];
        A[N-p+1]=i,N++;
        for (int j=2;j<=nm[i];j++) A[++N]=i;
    }

    printf("%d\n",N);
    for (int i=1;i<=N;i++) printf("%d ",A[i]);
    puts("");
}