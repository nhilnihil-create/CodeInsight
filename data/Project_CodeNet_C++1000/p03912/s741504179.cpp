# pragma GCC optimize("O3")
# include <bits/stdc++.h>
std::pair<int,int> DR[] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
# define maxn 100005
# define ll long long
# define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
# define rc(s) return cout << s,0
# define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define db(x) cerr << #x << " = " << x << '\n'
# define pb push_back
# define mp make_pair
# define sz(x) (int)((x).size())
//# define int ll
using namespace std;

int n,M,a[1 << 17],sum[1 << 17];
map<int,int>m[1 << 17];
int ans;

int32_t main(){_
    //freopen("input","r",stdin);
	cin >> n >> M;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		m[a[i] % M][a[i]]++;
		sum[a[i] % M]++;
	}	
	for(int i = 0;i <= M / 2;i++)
	{
		if((i == 0) || ((M % 2 == 0) && (i == M / 2))) ans += sum[i] / 2;
		else
		{
			int j = i;
			if(sum[i] < sum[M - i]) j = M - i;
			ans += sum[M - j];
			for(auto it : m[j])
			{
				if((it.second & 1) && sum[M - j])
					sum[M - j]--;
				ans += it.second / 2;
			}
			ans -= ((sum[M - j] + 1) / 2);
		}
	}
	rc(ans);
}
