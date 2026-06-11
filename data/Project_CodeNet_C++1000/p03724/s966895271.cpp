#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

int main()
{
	int n, m;
	cin >> n >> m;
	map<int,int> mp;
	rep(i,m){
		int a, b;
		cin >> a >> b;
		mp[a] ++;
		mp[b] ++;
	}
	for (auto x: mp){
		if(x.second % 2) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}
