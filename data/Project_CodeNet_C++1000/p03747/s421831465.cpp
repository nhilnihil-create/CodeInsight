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
int n , l , t , ans , x[MAXN] , w[MAXN];
vector<int> vec;
int32_t main()
{
	cin >> n >> l >> t;
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> x[i] >> w[i];
		if(w[i] == 1)
			vec.pb((t + x[i]) % l) , ans = (l - x[i] <= t ? ans + ((t - (l - x[i])) / l + 1) : ans + 0);
		else
			vec.pb(((x[i] - t) % l + l) % l) , ans = (x[i] < t ? ans - ((t - x[i] - 1) / l + 1) : ans + 0);
	}
	sort(all(vec)) , ans %= n , (ans += n) %= n;
	for(int i = ans ; i < n ; i ++)
		cout << vec[i] << endl;
	for(int i = 0 ; i < ans ; i ++)
		cout << vec[i] << endl;
	return 0;
}


