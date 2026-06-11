#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<list>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;


struct edge
{
	long long to; long long len;
	bool operator<(const edge& rhs) const {
		return len > rhs.len;
	}
};

int main() {
	ll n;
	cin >> n;
	ll i = 0;
	while (i*(i + 1) / 2 < n) {
		i++;
	}
	ll e = i * (i + 1) / 2 - n;
	REP(j, 1, i) {
		if (j != e) {
			cout << j << endl;
		}
	}
}