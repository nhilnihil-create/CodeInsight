#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e5+1000;
int h[maxn],n,lim[maxn];
bool cmp(int x,int y){return x>y;}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&h[i]);
    sort(h+1,h+1+n,cmp);
    lim[0]=h[1];lim[n]=h[n];
    for(int i=1;i<n;i++)lim[i]=h[i+1];
    int tar=0;
    while(tar+1<lim[tar+1]&&tar+1<n)tar++;
    int id=0;
    for(int i=1;i<n;i++)if(lim[i]>tar){id=i;}
    int l1=lim[tar]-1-tar,l2=id-tar;
    if(l1&1||l2&1)printf("First");
    else printf("Second");
    return 0;
}