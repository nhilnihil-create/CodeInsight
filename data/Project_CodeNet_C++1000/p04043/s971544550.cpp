#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef vector < int > vint;
typedef pair < int, int > pii;
typedef pair < int, bool > pib;
typedef unsigned long long ull;

#define PB push_back
#define MP make_pair
#define RANGE(V) V.begin(), V.end()
#define FOR(i,n) for(int i=0;i<n;++i)
#define FORN(i,n) for(int i=1;i<=n;++i)
#define debug(x) cerr<<#x<<":"<<x<<"\n";
#define FORS(i,n) for(int i=0;i<n.length();++i)
const int INF = INT_MAX;
const int MAX = 10000001;
const int M = 1000000007;
int mod{ 1000000007 };
int op(int a,int b, int m) {
	if (m == 0) return a * b;
	if (m == 1) return a + b;
	if (m == 2) return a / b;
	if (m == 3) return a - b;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int item;
	vint v(8);
	FOR(i, 3) {
		cin >> item;
		v[item]++;
	}
	if (v[5] == 2 && v[7] == 1) cout << "YES";
	else cout << "NO";
	return 0;	
}




