#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
static const int max_n = 200000;
static const int INF = 1e8;
static long long x,a,b,m,n,h,D=0,amax=1;
typedef pair<long long, long long> p;
static long long s[max_n],d[max_n];
static const int mod =1e9 + 7;
static int dist[111];//出発地からの最短距離
static long long cnt[111];//cnt[i] : 出発地からiまでの最短距離の回数
static vector<vector<int> > G;
static long long dp[max_n];
long long k = 0;
void solve(){
    long long sum = 0;
    for(int i=1 ; i<n ; i++){
        if(a * (s[i] - s[i-1]) > b ){
            sum += b;
        }else{
            sum += a * (s[i] - s[i-1]);
        }
    }
    cout << sum << endl;
}
int main(){
    cin >> n >> a >> b;
    for(int i=0 ; i<n ; i++){
        cin >> s[i];
    }
    solve();
    return 0;
}
