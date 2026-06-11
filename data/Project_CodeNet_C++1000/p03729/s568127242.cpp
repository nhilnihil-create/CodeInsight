/* 
	Author: ankrypt
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int
#define ff first
#define ss second
#define all(x) x.begin(), x.end() 
#define ub upper_bound
#define lb lower_bound
#define MAX_INT 15
#define fi(a, b, c, d) for(int a = b; i < c; i += d)
#define fl(a, b, c, d) for(ll a = b; i < c; i += d)
#define quit exit(0)

ll N, M, A, B, C;
ll arr[MAX_INT], arr1[MAX_INT], data[MAX_INT];
vector<ll> V;
string S, R, T;


int main() {
	cin >> S;
	cin >> R >> T;
	if(S[S.size() - 1] == R[0] && R[R.size() - 1] == T[0]) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}
/*
	Powered by Buggy Plugin
*/


