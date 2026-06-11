#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD = 1e9 + 7;

void no(){cout << "Impossible" << '\n';}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	deque<int> vec;
	vi odd; vi even;
 	for(int i = 0; i < m; i++)
	{
		int x; cin >> x;
		if(x&1) odd.pb(x);
		else vec.pb(x);
	}
	if(odd.size() > 2)
	{
		no(); return 0;
	}
	if(!odd.empty())
	{
		vec.push_front(odd[0]);
	}
	if(odd.size() >= 2)
	{
		vec.pb(odd[1]);
	}
	
	vi ans;
	for(int i = 0; i < m; i++)
	{
		if(i == 0)
		{
			if(m == 1)
			{
				ans.pb(1);
			}
			if(vec[i] > 1) ans.pb(vec[i] - 1);
		}
		else if(i == m - 1)
		{
			ans.pb(vec[i] + 1);
		}
		else
		{
			ans.pb(vec[i]);
		}
	}
	
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << ' ';
	}
	cout << '\n';
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
