#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,val[N];
bool judge(){
    if(n==1) return val[1]!=1;
    int num[2]={0,0};
    for(int i=1;i<=n;i++) num[val[i]%2]++;
    if(num[0]%2==1) return true;
    if(num[1]>1) return false;
    for(int i=1;i<=n;i++)
        if(val[i]%2==1&&val[i]!=1) val[i]--;
        else if(val[i]==1) return false;
    int gcd=val[1];
    for(int i=1;i<=n;i++) gcd=__gcd(gcd,val[i]);
    for(int i=1;i<=n;i++) val[i]/=gcd;
    return !judge();
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&val[i]);
    if(judge()) puts("First");
    else puts("Second");
    return 0;
}