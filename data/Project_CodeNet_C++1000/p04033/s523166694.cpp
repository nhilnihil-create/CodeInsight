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
	ll a, b;
	cin >> a >> b;

	if(a <= 0 && 0 <= b){
		cout << "Zero" << endl;
		return 0;
	} else if(0 < a){
		cout << "Positive" << endl;
		return 0;
	} else {
		ll num = b -  a + 1;
		if(num % 2 == 0){
			cout << "Positive" << endl;
		}
		else {
			cout << "Negative" << endl;
		}
	}
}
