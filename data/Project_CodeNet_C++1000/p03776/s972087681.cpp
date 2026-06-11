#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn = 55;
ll v[maxn];
ll C[maxn][maxn];
void init(){
    memset(C,0,sizeof(C));
    C[0][0]=1;
    for(int i=1;i<=50;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
}

int main(){
    int n,a,b;
    init();
    scanf("%d%d%d",&n,&a,&b);
    double ave=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&v[i]);
    }
    sort(v,v+n);
    reverse(v,v+n);
    for(int i=0;i<a;i++){
        ave+=v[i];
    }
    ave/=a;
    printf("%.6f\n",ave);
    int num=0,k=0;
    for(int i=0;i<n;i++){
        if(v[i]==v[a-1]){
            num++;
            if(i<a)
                k++;
        }
    }
    ll ans=0;
    if(k==a){
        for(int i=a;i<=b;i++){
            ans+=C[num][i];
        }
    }
    else 
        ans+=C[num][k];
    printf("%lld\n",ans);
    return 0;
}