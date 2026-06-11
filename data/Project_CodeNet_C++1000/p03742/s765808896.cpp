#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
int dp[10][10];
int SG(int x,int y){
    if(x<=1&&y<=1)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    set<int> s;
    for(int i=2;i<=x;i+=2)s.insert(SG(x-i,y+i/2));
    for(int i=2;i<=y;i+=2)s.insert(SG(x+i/2,y-i));
    for(int i=0;;i++)if(s.count(i)==0)return dp[x][y]=i;
}
void baoli(){
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++)dp[i][j]=-1;
    }
    for(int i=0;i<=5;i++){
        for(int j=i;j<=5;j++)cout<<i<<' '<<j<<' '<<SG(i,j)<<endl;
    }
}
int main(){
    //baoli();
    scanf("%lld%lld",&x,&y);
    if(x>y)swap(x,y);
    if(y-x<=1)printf("Brown\n");
    else printf("Alice\n");
    return 0;
}