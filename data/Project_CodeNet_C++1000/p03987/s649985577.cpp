#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll a[200105];
ll sum=0;
int d[200105][35],n;
 
void init()
{
    int i,j;
    for(i=0;i<n;i++)
        d[i][0]=i;
    for(j=1;(1<<j)<=n;j++)
    for(i=0;i+(1<<j)-1<n;i++)
        d[i][j]=a[d[i][j-1]] < a[d[i+(1<<(j-1))][j-1]]? d[i][j-1]:d[i+(1<<(j-1))][j-1];
}
int RMQ_indx_min(int s,int v)
{
    int k=(int)(log((v-s+1)*1.0)/log(2.0));
    return a[d[s][k]]<a[d[v-(1<<k)+1][k]]? d[s][k]:d[v-(1<<k)+1][k];
}
 
 
void dfs(int l,int r)
{
    if(l==r){
        sum+=(ll)a[l];
        return ;
    }
    int minn=RMQ_indx_min(l,r);
    sum=sum+(ll)(minn-l+1)*(r-minn+1)*a[minn];
    if(l<=minn-1)
        dfs(l,minn-1);
    if(r>=minn+1)
        dfs(minn+1,r);
}
int main (){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    init();
    dfs(0,n-1);
    printf("%lld\n",sum);
    return 0;
}