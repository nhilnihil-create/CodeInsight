#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long ll;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define UNIQUE(a)  (a).erase(unique((a).begin(),(a).end()),(a).end())
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const int INF = 10000000;

int n;
VI e[100000];
bool did[100000];

int grundy(int p){
	did[p]=true;
	int res=0;
	EACH(i,e[p]){
		int q=*i;
		if(did[q])continue; // is parent;
		res = res ^ (grundy(q) + 1);
	}
	return res;
}

int main() {
	cin>>n;
	REP(i,n-1){
		int x,y;
		cin>>x>>y;
		--x;--y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	cout << (grundy(0) ? "Alice" : "Bob") << endl;
	return 0;
}
