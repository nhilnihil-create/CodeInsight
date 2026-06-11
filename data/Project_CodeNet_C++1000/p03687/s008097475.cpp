#include<algorithm>
#include<cmath>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)

#define vll    vector<ll>
#define vvll   vector<vector<ll>>
#define all(x) (x).begin(),(x).end()

int main()
{	
	string s;
	cin >> s;

	map<char, int> pos;
	map<char, int> maxlength;

	//同じ文字間の長さ
	rep(i, s.size())
	{
		if (pos.count(s[i]) == 0)
		{
			maxlength[s[i]] = i;
		}
		else
		{
			maxlength[s[i]] = max(maxlength[s[i]], i - pos[s[i]] - 1);
		}

		pos[s[i]] = i;
	}

	//右端までの長さ
	for (auto p : pos)
	{
		maxlength[p.first] = max(maxlength[p.first], (int)s.size() - 1 - p.second);
	}

	int ans = 1000000000;

	for (auto l : maxlength)
	{
		ans = min(ans, l.second);
	}

	cout << ans << endl;

	return 0;
}