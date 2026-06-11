///supercalifragilisticexpialidocious.
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <bitset>
#include <complex>
using namespace std;
#define f first
#define s second
#define endl '\n'
#define PB pop_back
#define pb push_back
#define mp make_pair
#define int long long
#define sz(s) (int)s.size()
#define seper(n) setprecision(n)
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef map<int , int> mii;
typedef pair<int , int> pii;
typedef map<string , int> msi;
const int MAXN = 1e2 + 10;
int n , l , r , a[MAXN] , d[MAXN];
string ans = "Impossible";
int32_t main()
{
	cin >> n , r = n - 1;
	for(int i = 0 ; i < n ; i ++)
		cin >> a[i] , d[a[i]] ++;
	while(!d[l])
		l ++;
	while(!d[r])
		r --;
	if((r + 1) / 2 == l)
	{
		ans = "Possible";
		for(int i = l ; i <= r ; i ++)
		{
			if(i == l)
			{
				if(d[i] != ((r % 2) + 1))
					{ans = "Impossible" ; break;}
			}
			else
			{
				if(d[i] <= 1)
					{ans = "Impossible" ; break;}
			}
		}
	}
	return cout << ans << endl , 0;
}
