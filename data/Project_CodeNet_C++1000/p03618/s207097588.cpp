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
	string a;
	cin >> a;
	vector<int> count(26,0);
	rep(i,a.size()){
		count[a[i]-'a']++;
	}

	ll ans = 1;
	rep(i,26){
		ll now = count[i];
		For(j,i+1,26){
			ans += now * count[j];
		}
	}
	cout << ans << endl;
}
