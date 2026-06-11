#include<cstdio>
#include<iostream>
#include<cstring> 
using namespace std;
bool vis[10];
bool judge(int x){
    while(x!=0){
        int temp=x%10;
        if(vis[temp]==1)
            return false;
        x/=10;
    }
    return true;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
 
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=k;i++){
        int x;
        scanf("%d",&x);
        vis[x]=true;
    }
 
    for(int i=n; ;i++){
        if(judge(i)){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
} 