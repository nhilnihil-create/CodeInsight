//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;

//typedef
//------------------------------------------
typedef long long LL;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef pair<LL, LL> PLL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int MOD = 1000000007;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//main code

int main(int argc, char const* argv[])
{
	int n,i;
	cin >> n;
	for ( i = 1;i*(i+1)/2 < n; i++) {
	}
	for (int j = 1; j <= i; j++) {
		if (j == i*(i+1)/2 - n) {
			continue;
		}
		cout << j << endl;
	}
	return 0;
}
