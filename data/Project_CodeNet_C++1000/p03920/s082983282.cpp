#include<cstdio>
int main(){
    int n,m=0,k;
    scanf("%d",&n);
    while(m*(m+1)/2<n)m++;
    k=m*(m+1)/2-n;
    for(int i=1;i<k;i++)printf("%d\n",i);
    for(int i=k+1;i<=m;i++)printf("%d\n",i);
    return 0;
}