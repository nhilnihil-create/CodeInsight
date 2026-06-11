//#include <tourist>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <tuple>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <utility>
#include <complex>
#include <functional>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
//setprecision(15)有効数字15桁
//-std=c++14
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
struct edge {
    int to, cost;
};
int n, ma, mb;
vector<int> a, b;
vector<int> c;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>ma>>mb;
     int dp[401][401][41];
    for (int i = 0; i < n; i++)
    {
        int temp, temp1, temp2;
        cin >> temp>>temp1>>temp2;
        a.push_back(temp);
        b.push_back(temp1);
        c.push_back(temp2);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=400;j++){
            for(int k=0;k<=400;k++){
                dp[j][k][i]=0;
            }
        }
    }
    dp[a[0]][b[0]][0]=c[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=400;j++){
            for(int k=0;k<=400;k++){
                if(j-a[i]<0||k-b[i]<0){
                    dp[j][k][i]=dp[j][k][i-1];
                }
                else if(dp[j-a[i]][k-b[i]][i-1]==0&&j-a[i]==0&&k-b[i]==0){
                    if(dp[j][k][i-1]==0){
                        dp[j][k][i]=dp[j-a[i]][k-b[i]][i-1]+c[i];
                    }
                    else
                    dp[j][k][i]=min(dp[j][k][i-1],dp[j-a[i]][k-b[i]][i-1]+c[i]);
                }
              	else if(dp[j-a[i]][k-b[i]][i-1]==0){
                  dp[j][k][i]=dp[j][k][i-1];
                }
                else{
                    if(dp[j][k][i-1]==0){
                        dp[j][k][i]=dp[j-a[i]][k-b[i]][i-1]+c[i];
                    }
                    else
                    dp[j][k][i]=min(dp[j][k][i-1],dp[j-a[i]][k-b[i]][i-1]+c[i]);
                }
            }
        }
    }
    int i=1;
    int ans=INF;
    while(true){
        if(ma*i>400||mb*i>400){
            if(ans!=INF){
                break;
            }
            ans=-1;
            break;
        }
        if(dp[ma*i][mb*i][n-1]!=0){
            ans=min(ans,dp[ma*i][mb*i][n-1]);
        }
      i++;
    }
    cout<<ans<<"\n";
}



