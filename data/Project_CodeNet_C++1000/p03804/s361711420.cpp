/* When Talent doesn't work, Hard work beats Talent*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include"bits/stdc++.h"

using namespace std;

#define Fast_D cout<<fixed<<setprecision(13);
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl "\n"
#define int long long
#define double long double
#define all(v) v.begin(),v.end()
#define scanstr(s) cin>>ws; getline(cin,s);

const double PI = 3.141592653589793;

void solve()
{
	int n,m;
	cin >> n >> m;
	char tab[n][n], stb[m][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> tab[i][j];
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> stb[i][j];
		}
	}
	for(int i=0;i<n-m+1;i++)
	{
		for(int j=0;j<n-m+1;j++)
		{
			bool ok =1;
			for(int k=0;k<m;k++)
			{
				for(int l=0;l<m;l++)
				{
					if(tab[i+k][j+l] != stb[k][l])
					{
						ok = 0;
						break ;
					}
				}
			}
			if(ok==1)
			{
				cout << "Yes\n";
				return ;
			}
		}
	}
	cout << "No\n";
}

int32_t main()
{
	FastIO;
	Fast_D;
	solve();
	return 0;
}
