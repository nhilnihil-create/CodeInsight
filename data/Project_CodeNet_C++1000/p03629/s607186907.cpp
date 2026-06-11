#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define IO ios::sync_with_stdio(false),cin.tie(0)
#define FIN freopen("D://code//in.txt", "r", stdin)
#define ppr(i,x,n) for(int i = x;i <= n;i++)
#define rpp(i,n,x) for(int i = n;i >= x;i--)
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

inline int read() {//读入挂
    int ret = 0, c, f = 1;
    for(c = getchar(); !(isdigit(c) || c == '-'); c = getchar());
    if(c == '-') f = -1, c = getchar();
    for(; isdigit(c); c = getchar()) ret = ret * 10 + c - '0';
    if(f < 0) ret = -ret;
    return ret;
}
int nextt[maxn][26];
int now[26],area[maxn];
int tot,tmp;
set<int >S;
int main()
{
	IO;
	tot = 0;
	string s;
	string ans;
	cin>>s;
	rpp(i,s.size()-1,0)
	{
		int gg = s[i] - 'a';
		S.insert(gg);
		area[i] = tot;
		if(S.size() == 26)
		{
			tot++;
			S.clear();
		}
	}
	if(tot == 0)
	{
		ppr(i,0,25)
		{
			if(S.count(i) == 0)
			{
				char minn= i+'a';
				cout<<minn<<endl;
				return 0;
			}
		}
	}
	rpp(i,s.size()-1,0)
	{
		ppr(j,0,25)
		{
			nextt[i][j] = now[j];
		}
		now[s[i] - 'a'] = i;
	}
	ppr(i,0,25)
	{
		if(S.count(i) == 0)
		{
			ans += (i + 'a');
			tmp = now[i];
			break;
		}
		
	}
	ppr(i,1,tot)
	{
		ppr(j,0,25)
		{
			if(area[nextt[tmp][j]] == area[tmp]-1)
			{
				char minn = j + 'a';
				ans += minn;
				tmp = nextt[tmp][j];
				break;
			}
		}
	}
	ppr(i,0,25)
	{
		if(nextt[tmp][i] == 0)
		{
			char minn = i + 'a';
			ans += minn;
			break;
		}
	}
	cout<<ans<<endl;
}