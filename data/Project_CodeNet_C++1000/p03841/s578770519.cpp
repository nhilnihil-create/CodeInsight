#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
const int maxn = 5e2 + 20;

int a[maxn] , t[maxn] , res[maxn * maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> a[i] , t[i] = i;

	set<pair<int , int> > st , last;
	for(int i = 1; i <= n; i++)
	{
		if(i > 1)
			st.insert({a[i] , i});
		else
			last.insert({a[i] , i});
	}

	vector<int> garbage;
	for(int i = 1; i <= n * n; i++)
	{
		if(!last.empty() && (last.begin() -> first) == i)
		{
			res[i] = last.begin() -> second;
			last.erase(last.begin());

			for(int _ = 0; _ < n - res[i]; _++)
				garbage.pb(res[i]);
		}
		else if(!st.empty())
		{
			int x = st.begin() -> second;
			st.erase(st.begin());
			res[i] = x;

			if(a[x] <= i)
				return cout << "No" << endl , 0;

			t[x]--;
			if(t[x] > 1)
				st.insert({a[x] , x});
			else
				last.insert({a[x] , x});
		}
		else if(!garbage.empty())
		{
			res[i] = garbage.back();
			garbage.pop_back();
		}
		else
			return cout << "No" << endl , 0;
	}

	cout << "Yes" << endl;
	for(int i = 1; i <= n * n; i++)
		cout << res[i] << " ";
	cout << endl;
}
















