#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, x[N], l[N], r[N], ans[N];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x[i]);
		ans[x[i]] = i;
		l[i] = i - 1;
		r[i] = n - i;
	}
	for(int i = 1; i <= n * n; i++){
		if(ans[i])
			continue;
		
		int p = -1;
		
		for(int j = 1; j <= n; j++)
			if(l[j] > 0 && i < x[j] && (p == -1 || x[p] > x[j]))
				p = j;
		
		if(p != -1){
			ans[i] = p;
			l[p]--;
			continue;
		}
		
		for(int j = 1; j <= n; j++)
			if(r[j] > 0 && x[j] < i)
				p = j;
		
		if(p != -1){
			ans[i] = p;
			r[p]--;
			continue;
		}
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i = 1; i <= n * n; i++)
		printf("%d ", ans[i]);
	return 0;
}
