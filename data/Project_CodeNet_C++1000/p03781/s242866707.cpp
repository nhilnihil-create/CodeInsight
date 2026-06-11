# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<cstdio>
using namespace std;
typedef long long int ll;
const int N = 1000000;
const ll mod = 1000000007;
const ll INF = std::numeric_limits<long long>::max();
#define rep(i,n) for(ll i=(ll)0;i<(ll)n;++i)
#define srep(i,s) rep(i,(ll)s.size())
#define vin(n,v) rep(i,n)cin>>v[i]
#define ALL(x) x.begin(),x.end()
#define pp pair<ll,ll>
#define fi first
#define se second
#define sz size
void YN(bool b) { cout << (b ? "YES" : "NO") << endl; }
void yn(bool b) { cout << (b ? "Yes" : "No") << endl; }
ll n, num = 0;
int main(){
	cin >> n;
	rep(i, 100000000) {
		num += i;
		if (num >= n){ cout << i << endl; break; }
	}
	return 0;
}