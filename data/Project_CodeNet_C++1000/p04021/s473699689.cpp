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
#define PB pop_back 
#define pb push_back
#define mp make_pair
#define int long long
#define y1 y_golabi
#define sz(s) (int)s.size()
#define seper(n) setprecision(n)
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
typedef long long ll;
typedef map<int , int> mii;
typedef pair<int , int> pii;
typedef map<string , int> msi;
typedef pair<int , string> pis;
typedef pair<int , pair<int , int> > piii;
const int MAXN = 1e5 + 10;
int n , ans , b[MAXN];
pii a[MAXN];
int32_t main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> a[i].f , a[i].s = i;
	sort(a , a + n);
	for(int i = 0 ; i < n ; i ++)
		b[a[i].s] = i;
	for(int i = 1 ; i < n ; i += 2)
		ans += (!(b[i] & 1));
	return cout << ans << endl , 0;
}
	
