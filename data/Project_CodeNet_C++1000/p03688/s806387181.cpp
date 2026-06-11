#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef pair <int, int> pii;

//#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
//  order_of_key (k) : Number of items strictly smaller than k .
//  find_by_order(k) : K-th element in a set (counting from zero).
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define F first
#define S second
#define show(a) cerr << #a <<" -> "<< a <<"\n"
#define fo(a, b, c, d) for(int (a) = (b); (a) <= (c); (a) += (d))
#define foo(a, b, c ,d) for(int (a) = (b); (a) >= (c); (a) -= (d))
//#define int ll

const int N = 1e5 + 5;
const int INF = INT_MAX;

int n, a[N], mn = INF, mx = 0;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	if(mn == mx) {
		bool ok1 = 1, ok2 = 1;
		for(int i = 1; i <= n; ++i) {
			if(a[i] != n - 1) ok1 = 0;
			if(a[i] * 2 > n) ok2 = 0;
		}
		if(ok1 || ok2) 
			cout << "Yes\n";
		else 
			cout << "No\n";
	} else if(mn + 1 == mx) {
		int x = 0, y = 0;
		for(int i = 1; i <= n; ++i) {
			if(a[i] == mn) ++x;
			if(a[i] == mx) ++y;
		} 
		if(x + 1 <= mx && mx <= x + y / 2) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}	
	} else {
		cout << "No\n";
	}
	return 0;
}
/*
	If you only do what you can do, 
	You will never be more than you are now!
*/