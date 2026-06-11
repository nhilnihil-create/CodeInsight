#include<bits/stdc++.h>
using namespace std;
const int maxn=103;
int n,m,a[maxn],c,p1,p2,ANS[maxn],CNT;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",a+i);
        c+=(a[i]&1);
        if((a[i]&1)&&c==1)p1=a[i],m--,i--;
        if((a[i]&1)&&c==2)p2=a[i],m--,i--;
    }
    if(c>=3){puts("Impossible");return 0;}
    if(c==0){
        if(m==1)ANS[++CNT]=1,ANS[++CNT]=a[1]-1,printf("%d\n",a[1]);
        else{for(int i=1;i<=m;i++)ANS[++CNT]=(i==1?a[i]-1:(i<m?a[i]:a[i]+1)),printf("%d ",a[i]);puts("");}
    }
    if(c==1){
        if(p1>1)ANS[++CNT]=p1-1;
        printf("%d ",p1);
        if(!m)ANS[++CNT]=1;
        else{for(int i=1;i<=m;i++)ANS[++CNT]=(i<m?a[i]:a[i]+1),printf("%d ",a[i]);}
        puts("");
    }
    if(c==2){
        if(p1>1)ANS[++CNT]=p1-1;
        printf("%d ",p1);
        for(int i=1;i<=m;i++)ANS[++CNT]=a[i],printf("%d ",a[i]);
        ANS[++CNT]=p2+1;
        printf("%d\n",p2);
    }
    printf("%d\n",CNT);
    for(int i=1;i<=CNT;i++)printf("%d ",ANS[i]);
    return 0;
}