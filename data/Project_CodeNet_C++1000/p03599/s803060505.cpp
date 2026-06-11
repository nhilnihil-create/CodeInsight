#include <bits/stdc++.h>
using namespace std;
 
const int N = 3000;
 
int a,b,c,d,e,f,ans,total;
int dp[N+10][N+10];
 
void dfs(int sugar,int water){
    if (dp[sugar][water]!=-1) return;
    dp[sugar][water] = 1;
    if (sugar*100>e*water) return;
    if (sugar+water>f) return;
    if (total==0 || sugar*total>ans*(sugar+water)){
        if (water>0){
            ans = sugar;
            total = sugar + water;
        }
    }
    dfs(sugar,water+100*a);
    dfs(sugar,water+100*b);
    dfs(sugar+c,water);
    dfs(sugar+d,water);
}
 
int main(){
    //freopen("F:\\rush.txt","r",stdin);
    memset(dp,255,sizeof dp);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> a >> b >> c >> d >> e >> f;
    dfs(0,0);
    cout << total << ' '<< ans << endl;
    return 0;
}