//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//math
//-------------------------------------------
template<class T> inline T sqr(T x) { return x*x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(b)  (b).begin(),(b).end()
#define RALL(b) (b).rbegin(), (b).rend()
#define PB push_back
#define MP make_pair
#define SZ(b) int((b).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);

//clear memory
#define CLR(b) memset((b), 0 ,sizeof(b))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
int main()
{
	int n;
	cin >> n;
	auto p = VI(n);

	REP(i, n) cin >> p[i];

	auto b = vector<bool>(n);
	REP(i, n) if (p[i] == i + 1) b[i] = true; else b[i] = false;

	int c = 0;

	REP(i, n - 1) if (b[i] && b[i + 1]) {
		c++;
		b[i] = false;
		b[i + 1] = false;
	}
	REP(i, n) if (b[i]) c++;
	cout << c << endl;
	return 0;
}