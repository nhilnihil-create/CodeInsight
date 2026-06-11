#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 205;
const ll INF = 1e10;
ll d[MAX_N][MAX_N];
vector<int> r;

void init()
{
	rep(i,MAX_N)
	{
		rep(j,MAX_N)
		{
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}
}

int main()
{
	init();
	int N,M,R;
	cin >> N >> M >> R;
	rep(i,R)
	{
		int p;
		cin >> p;
		p--;
		r.push_back(p);
	}
	sort(r.begin(),r.end());
	rep(i,M)
	{
		int a,b;
		ll c;
		cin >> a >> b >> c;
		a--; b--;
		d[a][b] = c;
		d[b][a] = c;
	}
	rep(k,N)
	{
		rep(i,N)
		{
			rep(j,N)
			{
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	/*
	rep(i,N)
	{
		rep(j,N)
		{
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	cout << "a" << endl;
	*/
	ll ans = INF;
	do
	{
		ll temp = 0;
		rep(i,R-1)
		{
			temp += d[r[i]][r[i+1]];
		}
		/*
		rep(i,R)
		{
			cout << r[i] << " ";
		}
		cout << temp << endl;
		*/
		ans = min(ans,temp);
	}
	while(next_permutation(r.begin(), r.end()));

	cout << ans << endl;
	return 0;
}