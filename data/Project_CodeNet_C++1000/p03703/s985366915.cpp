//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include<iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<pair<long long, long long>, null_type, less<pair<long long, long long> >, rb_tree_tag, tree_order_statistics_node_update>
const int N = 2e5 + 5;
ordered_set s;
long long a[N];
long long ans = 0;
int main() 
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
    {
		cin >> a[i + 1];
		a[i + 1] += a[i] - k;
	}
	for (int i = 0; i <= n; i++) 
    {
		int tmp = s.order_of_key({a[i], i});
		ans += tmp;
		s.insert({a[i], -i});
	}
	cout << ans;
}



	
            


 