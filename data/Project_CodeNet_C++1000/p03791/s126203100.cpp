#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--) 
#define Rep(i,a) for(int i = 0; i < a; i++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ab(x) ((x) < 0 ? -(x) : (x))
using namespace std;
typedef long long LL;
typedef map<int, int>::iterator mit;
typedef set<int>::iterator sit;
const int N = 1e5 + 10, mod = 1e9 + 7;
int a[N];
int main() {
	int n; scanf("%d",&n);	
	rep(i,1,n) scanf("%d",a + i);
	int ans = 1, cur = 1;
	rep(i,1,n) {
		while (cur < n && (cur - i + 1) * 2 - 1 <= a[cur]) cur++;
		ans = 1LL * ans * (cur - i + 1) % mod;
	}
	cout <<ans<<endl;
	return 0;
}
