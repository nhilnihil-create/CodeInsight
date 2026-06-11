#define _USE_MATH_DEFINES
#include<cmath>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<iostream>
#include<algorithm>
#include<string>
#include<utility>
#include<tuple>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<numeric>
#include<functional>
#include<iomanip>
#include<random>
using namespace std;
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define REP(i,n) for(int i = 0;i < n;i++)
#define FOR(i,a,b) for(int i = a;i < b;i++)
#define ALL(x) (x).begin(),(x).end()
#define dump(x) cout << (x) << endl
#define LMAX 9223372036854775807LL
#define LMIN -9223372036854775807LL
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	fill((T*)array, (T*)(array + N), val);
}

const ll INF = 1e18;

int main() {
	IOS;
	string s;
	cin >> s;
	if (s.size() < 4) {
		dump("No"); return 0;
	}

	dump(s.substr(0,4) == "YAKI" ? "Yes" : "No");
	return 0;
}