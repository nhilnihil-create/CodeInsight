#include <iostream>
#include <vector>
#include <climits>

using namespace std;
struct Drag{
    int a, b, c;
};
int gcd(int a, int b){
    int r = a%b;
    return r==0 ? b : gcd(b, r);
}
int main(){
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n*10+1, vector<int>(n*10+1, INT_MAX)));
    dp[0][0][0]=0;
    // vector<Drag> drag(n);
    int a, b, c;
    int ans=INT_MAX;
    for(int i=1;i<=n;++i){
        // cin >> drag[i].a >> drag[i].b >> drag[i].c;
        cin >> a >> b >> c;
        for(int x=n*10;x>=0;--x){
            for(int y=n*10;y>=0;--y){
                if(x-a>=0 && y-b>=0 && dp[i-1][x-a][y-b]!=INT_MAX)
                    dp[i][x][y]=dp[i-1][x-a][y-b]+c;
                dp[i][x][y] = min(dp[i][x][y], dp[i-1][x][y]);
                if(ans>dp[i][x][y] && x!=0){
                    int g = gcd(x, y);
                    if(x/g==ma && y/g==mb)
                        ans=dp[i][x][y];
                }
            }
        }
    }
    cout << (ans==INT_MAX ? -1 : ans);
    return 0;
}