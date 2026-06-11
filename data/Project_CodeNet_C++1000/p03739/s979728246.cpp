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
	// 0項までの和を+にするか-にするか。
	ll hu = 0;
	ll sum = 0;
	rep(i,n){
		sum += a[i];
		if(i % 2 == 0){
			if(sum >= 0){
				// -1 にする
				hu += sum + 1;
				sum = -1;
			}
		} else {
			if(sum <= 0){
				hu += abs(sum) + 1;
				sum = 1;
			}
		}
	}

	ll sei = 0;
	sum = 0;
	rep(i,n){
		sum += a[i];
		if(i % 2 == 0){
			if(sum<=0){
				sei += abs(sum) + 1;
				sum = 1;
			} 
		} else {
			if(sum >= 0){
				sei += sum + 1;
				sum = -1;
			}
		}
	}
	cout << min(sei,hu) << endl;
}
