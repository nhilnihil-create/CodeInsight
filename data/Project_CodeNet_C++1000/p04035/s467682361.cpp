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
	ll n, l;
	cin >> n >> l;
	vector<ll> a(n);
	rep(i, n)cin>>a[i];
	ll M = 0;
	int index = 0;
	rep(i,n-1){
		if(chmax(M, a[i]+a[i+1])) index = i;
	}
	if(M < l){
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	rep(i,index){
		cout << i + 1 << endl;
	}
	for(int i = n - 1; i > index; i--){
		cout << i << endl;
	}
}
