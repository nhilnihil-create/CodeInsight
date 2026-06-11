#include<bits/stdc++.h>
#include<climits>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int              long long
#define umapii           unordered_map<int,int>
#define pqmaxi           priority_queue<int>
#define pqmini           priority_queue<int,vector<int>,greater<int>>
#define arr(type,a,n)    type* a = new type[n];
#define ff               first
#define ss               second
#define pb               push_back
#define w(t)             int t;cin>>t;while(t--)
#define popb             pop_back
#define mod              pow(10,9)+7;
#define mapii            map<int,int>
#define mp               make_pair
#define vint             vector<int>
#define presesion        fixed<<presesion(y)<<x
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>pbds;
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	bool flag = false;
	int a, b, c;
	cin >> a >> b >> c;
	int t = 0;
	for (int i = 1; i < 1e6; i++) {
		t += a;
		if (t % b == c) {
			flag = true;
		}
	}
	if (flag) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

}
