#include<iostream>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

const int INF = 1e9;
int a[100], b[100], c[100];
int dp[500][500];

/*
dp[i][a][b]
iまでの薬品を買って Aaグラム Bbグラムとしたときの
必要な最小予算
*/

int main() {
    int N,MA,MB; cin >> N >> MA >> MB;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            dp[i][j] = INF;
        }
    } 
    dp[0][0] = 0;
    
    
    for (int i = 0; i < N; i++) {
        for (int j = 499; j >= 0; j--) {
            for (int k = 499; k >= 0; k--) {
                if (j-a[i] >= 0 && k-b[i] >= 0) {
                    chmin(dp[j][k],dp[j-a[i]][k-b[i]]+c[i]);
                }
            }
        }
    }
    int res = INF;
    for (int i = 1; i*MA < 500 && i*MB < 500; i++) {
        chmin(res,dp[i*MA][i*MB]);
    }
    if (res == INF) {
        cout << "-1\n";
    } else cout << res << endl;
}