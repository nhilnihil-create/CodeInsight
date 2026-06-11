#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n)cin>>a[i];


	// 最初を負にする
	ll sum = a[0];
	ll ans = 0;
	if(sum >= 0){
		ans = (sum - (-1));
		sum = -1;
	}
	For(i,1,n){
		sum += a[i];
		// 符号が変わるなら何もしない
		if(sum * (sum-a[i]) < 0); // ok
		else {
			// sumが正なら負に、sumが負なら正にする
			// sum が 0 のとき注意が必要
			if(sum == 0){
				if(sum-a[i] < 0){
					sum = 1;
					ans ++;
				} else {
					ans ++;
					sum = -1;
				}
			}
			else if(sum > 0){
				ans += (sum - (-1));
				sum = -1;
			} else {
				ans += (1 - sum);
				sum = 1;
			}
		}
	}
	ll tmp = ans;
	sum = a[0];
	ans = 0;
	if(sum <= 0){
		ans = (1 - sum);
		sum = 1;
	}
	For(i,1,n){
		sum += a[i];
		// 符号が変わるなら何もしない
		if(sum * (sum-a[i]) < 0); // ok
		else {
			// sumが正なら負に、sumが負なら正にする
			// sum が 0 のとき注意が必要
			if(sum == 0){
				if(sum-a[i] < 0){
					sum = 1;
					ans ++;
				} else {
					ans ++;
					sum = -1;
				}
			}
			else if(sum > 0){
				ans += (sum - (-1));
				sum = -1;
			} else {
				ans += (1 - sum);
				sum = 1;
			}
		}
	}
	ans = min(tmp,ans);
	cout << ans << endl;
}
