#include <iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
    int n,k,vis[10]={0},ans;
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        int tem;
        scanf("%d",&tem);
        vis[tem]=1;
    }
    ans=n;
    while(1){
        int tem=ans;
        int flag=1;
        while(tem!=0){
            if(vis[tem%10]){flag=0;break;}
            tem/=10;
        }
        if(flag)break;
        ans++;
    }
    cout<<ans;
}
