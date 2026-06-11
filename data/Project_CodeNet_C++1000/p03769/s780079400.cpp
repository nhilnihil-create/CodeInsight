#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int q[222];
int cnt=0,l,r;
void work(ll x){
    if(x==0)return ;
    if(x%2==0){
        //int idx=l--;
        work(x-1);
        q[l--]=++cnt;

    }
    else {
        work(x/2);
        q[r++]=++cnt;
    }
}
int main()
{
    ll n;
    scanf("%lld",&n);
    l=100,r=101;
    cnt=0;
    work(n);
    printf("%d\n",cnt*2);
    for(int i=l+1;i<r;i++){
        printf("%d ",q[i]);
    }
    for(int i=1;i<=cnt;i++){
        printf("%d",i);
        if(i!=cnt)printf(" ");
        else printf("\n");
    }
    return 0;
}
