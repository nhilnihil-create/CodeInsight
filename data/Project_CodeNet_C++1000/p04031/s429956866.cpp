#include <bits/stdc++.h>


#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define loop(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b,c) for(int i=a; i<b; i+=c)
#define brep(i,a,b,c) for(int i=a; i>b; i-=c)
#define tc(t) int t; cin>>t; while(t--)
#define sz(v) int((v).size())
#define pb push_back

const int N = 2e5 + 10;


using namespace std;

int main()
{



	IOS;

	int n;

	cin >> n;

	int a[n];

	ll result = 1e9;


	loop(i, n)
	{
		cin >> a[i];
	}


	sort(a, a + n);


	for (int i = a[0]; i <= a[n - 1]; i++)
	{

		int ans = 0;
		for (int j = 0; j < n; j++)
		{
			ans += (a[j] - i) * (a[j] - i);
		}

		if (ans < result)
		{
			result = ans;
		}
	}

	cout << result;

	return 0;
}
