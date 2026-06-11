#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000






int main() {
	vector<int>a;
	map<int, int>mp;
	int n, x, ans;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &x);
		a.push_back(x);
		mp[x] = i;
	}
	sort(a.begin(), a.end());
	ans = 0;
	f(i, n) {
		x = (mp[a[i]]) % 2;
		if (i % 2 != x)ans++;
	}
	ans /= 2;
	printf("%d\n", ans);
	return 0;
}