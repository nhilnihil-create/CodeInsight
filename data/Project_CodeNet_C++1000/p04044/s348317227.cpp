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
bool compare(string a, string b) {
	return (a + b < b + a);
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	int n, l;
	cin >> n >>l;
	vector<string> v(n);
	FOR(i, n) cin >> v[i];
	sort(v.begin(), v.end(), compare);
	for (auto& i : v) {
		cout << i;
	}
	return 0;	
}




