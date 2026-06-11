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
typedef pair<int , pair<int , int> > piii;
const int MAXN = 1e5 + 10;
int n , a , b , h[MAXN];
bool check(int x)
{
	int idx = 0 , ans = 0;
	while(x * b < h[idx])
		ans += ((h[idx] - x * b) + a - b - 1) / (a - b) , idx ++;
	if(x < ans)
		return false;
	return true;
}
int32_t main()
{
	cin >> n >> a >> b;
	for(int i = 0 ; i < n ; i ++)
		cin >> h[i];
	sort(h , h + n) , reverse(h , h + n);
	int l = -1 , r = (1e18 + 1e2) / b;
	while(r - l > 1)
	{
		int mid = (l + r) >> 1;
		if(check(mid))
			r = mid;
		else
			l = mid;
	}
	return cout << r << endl , 0;
}
														
