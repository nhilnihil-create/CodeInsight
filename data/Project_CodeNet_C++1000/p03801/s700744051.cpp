#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;
 
typedef pair <int, int> pii;
const long long INF = 1e18;
const int mod = 1e9 + 7;//1e9 + 7;//786433;//998244353;
const double Pi = acos(-1);
 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
int a[100005], sz[100005];
long long ans[100005];
priority_queue <pair <int, int> > pq;

signed main()
{
	Fastio();
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		sz[i] = 1;
		cin >> a[i];
		pq.push(mp(a[i], i));
	}
	while((int)pq.size() > 1)
	{
		int temp = pq.top().fi, id = pq.top().se;
		pq.pop();
		int temp2 = pq.top().fi, id2 = pq.top().se;
		pq.pop();
		ans[id] += 1ll * sz[id] * (temp - temp2);
		pq.push(mp(temp2, min(id, id2)));
		sz[min(id, id2)] += sz[max(id, id2)]; 
	}
	ans[1] += 1ll * n * pq.top().fi;
	for(int i = 1; i <= n; i++)
	{
		cout << ans[i] << '\n';
	}
}