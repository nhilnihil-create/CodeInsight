#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, l, t, a[N], b[N], w[N], ans;
int main()
{                         
	scanf("%d%d%d", &n, &l, &t);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &a[i], &w[i]);
		if(w[i] == 1)
			b[i] = (a[i] + t) % l;
		else
			b[i] = (a[i] - t % l + l) % l;
	}
	sort(b, b + n);

	for(int i = 1; i < n; i++){
		if(w[0] == w[i])
			continue;
		int p1 = a[0];
		int p2 = a[i];
		ans = (ans + t / l * 2) % n;
		ll d;
		
		if(w[0] == 1)
			d = (p2 - p1); 
		else
			d = (p1 - p2 + l);   
		
		if(d <= t % l * 2)
			ans = (ans + 1) % n;
		
		d += l;
		
		if(d <= t % l * 2)
			ans = (ans + 1) % n;
	}
	if(w[0] == 2)
		ans = (n - ans) % n;
	
	int cur, pos;

	if(w[0] == 1)
		cur = (a[0] + t) % l;
	else
		cur = (a[0] - t % l + l) % l;
	
	for(int i = 0; i < n; i++)
		if(b[i] == cur){
			pos = i;
			if(w[0] == 2)
				break;
		}

	for(int i = 0; i < n; i++)
		printf("%d\n", b[(i + pos - ans + n) % n]);
	return 0;
}
