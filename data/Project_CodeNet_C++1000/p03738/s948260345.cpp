#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9;
double pi = acos(-1);

#define fast_io ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define en "\n"
#define ff first
#define ss second
#define sp(x) fixed << setprecision(x)
#define VECT(v)  vector<int>v
#define SCAN(v)  int temp; for(int i=0; i<n; i++) {cin>>temp; v.push_back(temp);}
#define PRINT(v) for(int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << en;
#define SORT(v)  sort(v.begin(), v.end());
#define RSORT(v) sort(v.begin(), v.end(), greater<>())
#define CASEP(v) cout<<"Case "<<tc<<": "<<v<<"\n"
#define DEBUG(v) cout << v << " "; cout << en;

string check(string a, string b)
{
	string ans = "";

	if(a.size() > b.size())
	{
		ans = "GREATER";
		return ans;
	}
	else if(a.size() < b.size())
	{
		ans = "LESS";
		return ans;
	}
	else
	{
		ll len = a.size();
		for(int i = 0; i < len; i++)
		{
			if(a[i] > b[i])
			{
				ans = "GREATER";
				return ans;
			}
			else if(a[i] < b[i])
			{
				ans = "LESS";
				return ans;
			}
			else
				ans = "EQUAL";
		}
		return ans;
	}
}

int main(void)
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	fast_io

	string a, b;
	cin >> a >> b;

	cout << check(a, b) << en;

	return 0;
}