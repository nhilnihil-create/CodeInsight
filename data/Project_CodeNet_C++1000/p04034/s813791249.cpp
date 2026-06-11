#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,x,y,b[100010];
bool a[100010];
int main(){
    scanf("%d%d",&n,&m);
    a[1]=1;
    for (int i=1; i<=n; i++)
        b[i]=1;
    for (int i=1; i<=m; i++){
        scanf("%d%d",&x,&y);
        if (a[x]==1){
            a[y]=1;
            if (b[x]==1) a[x]=0;
        }
        b[y]++;
        b[x]--;
    }
    int sum=0;
    for (int i=1; i<=n; i++)
        sum+=a[i];
    printf("%d\n",sum);
}