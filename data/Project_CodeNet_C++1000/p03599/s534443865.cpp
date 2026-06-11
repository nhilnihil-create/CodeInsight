#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool dp[6000][6000];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    dp[0][0] = true;
    double mx = -1;
    int A = 0, B = 0;
    rep(i,f+1)rep(j,f+1){
        if(!dp[i][j]) continue;
        if(i+100*a+j <= f) dp[i+100*a][j] = true;
        if(i+100*b+j <= f) dp[i+100*b][j] = true;
        if(i+j+c <= f && j+c <= e*(i/100)) dp[i][j+c] = true;
        if(i+j+d <= f && j+d <= e*(i/100)) dp[i][j+d] = true;
        if(i+j == 0) continue;
        double milk = (double)(100*j) / (double)(i+j);
        if(mx < milk){
            mx = milk;
            A = i+j;
            B = j;
        }
    }
    cout << A << " " << B << endl;
	return 0;
}