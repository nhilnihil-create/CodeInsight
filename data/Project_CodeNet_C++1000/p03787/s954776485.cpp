#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100010;
bool vst[N];
vector<int> mp[N];
int dep[N];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main() 
{
	int n, m;
	n = read();
	m = read();
	for(int i = 1; i <= m; i ++) 
	{
		int x, y;
		x = read();
		y = read();
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	ll cnt[2] = {0, 0};
	ll siz1(0);
	fill(vst + 1, vst + 1 + n, 0);
	for(int i = 1; i <= n; i ++) 
		if(!vst[i]) 
		{
			vector<int> q;
			q.push_back(i);
			vst[i] = 1;
			dep[i] = 0;
			bool isBip(1);
			for(int op(0); op < (int)q.size(); op ++) 
			{
				int v(q[op]);
				for(int y : mp[v]) 
					if(!vst[y]) 
					{
						vst[y] = 1;
						q.push_back(y);
						dep[y] = dep[v] + 1;
					}
					else 
						if((dep[v] - dep[y]) % 2 == 0) 
							isBip = 0;
			}
			if(q.size() == 1) siz1 += q.size();
			else cnt[isBip]++;
		}
	ll ans(0);
	ans += siz1 * siz1 + 2 * siz1 * (n - siz1);
	ans += (cnt[0] + cnt[1]) * (cnt[0] + cnt[1]);
	ans += cnt[1] * cnt[1];
	cout << ans << endl;
}	
