#include<bits/stdc++.h>
using namespace std;
int n,f[2000001],add,p=1e9+7;
int main(){
    scanf("%d",&n);
    f[n]=n;
    f[n-1]=(long long)n*n%p;
    for(int i=n-2;i>=1;--i)
    {
        add=(add+f[i+3])%p;
        f[i]=f[i+1];
        f[i]=(f[i]+(long long)(n-1)*(n-1)%p)%p;
        f[i]=(f[i]+add)%p;
        f[i]=(f[i]+i+1)%p;
    }
    printf("%d",f[1]);
}