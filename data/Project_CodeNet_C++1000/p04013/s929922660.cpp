#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line
ll dp[52][52][2510]; // おそらく初期値は全部0
int main()
{
	int n, a;
	cin >> n >> a; // average を a 円にする！
	vector<int> x(n);
	rep(i,n) cin >> x[i]; 
	// dp[i][j][k] := i 枚目までで j 枚選択して和を k にするときの組み合わせが何通りあるか。 

	rep(i,52){
		rep(j,52){
			rep(k,2510){
				// 任意の i に対して j == 0 , k == 0 は1
				if(j == 0 && k == 0) dp[i][j][k] = 1;
				else dp[i][j][k] = 0;
			}
		}
	}

	/* 遷移は、今見ているカードの数字が X のとき,Xを使うなら X が j 枚目になるから
	   dp[i][j][k] = dp[i-1][j-1][k-X] + dp[i-1][j][k];
	 */

	ll ans = 0;
	for(int i = 1; i <= n; i++){
		int X = x[i-1]; 
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= 2500; k++){
				if(k <= X - 1){
					// (X - 1　までは、そいつを使うことはできない)
					dp[i][j][k] = dp[i-1][j][k];
				} else {
					dp[i][j][k] = dp[i-1][j-1][k-X] + dp[i-1][j][k];
				}
				// if(j*a==k) ans += dp[i][j][k]とすると、同じカードの選び方のものが何度もたされしまうので、51~53行目で ans を作って行く
			}
		}
	}

	// n 枚目までで j 枚選んだとき j * a になるやつをansに足す
	rep(j,n+1){
		ans += dp[n][j][j*a] ;
	}
	// なぜか1大きい値が出力されるので-1する
	cout << ans - 1<< endl;
	// 原因わかった。j = 0 のときに、和が0となるやつが1通りあって、それが ans にたされているからだ。
}
