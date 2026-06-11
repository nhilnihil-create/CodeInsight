#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[101000];
long long res = 1, Mod = 1000000007;
int main(){
    int i, pv = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    
    for(i=1;i<=n;i++){
        if(pv<i)pv=i;
        while(pv < n && w[pv+1] >= (pv+1-i)*2 && w[pv] >= (pv+1-i)*2-1)pv++;
        res=res*(pv-i+1)%Mod;
    }
    printf("%lld\n",res);
}