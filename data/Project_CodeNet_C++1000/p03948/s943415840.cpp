#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;

int main(){
	int n,t;
	cin >> n >> t;

	vector<int> a(n);
	for(int i = 0;i < n;i++)cin >> a[i];

	int mn = 1000000010;
	int mx = 0;
	for(int i = 0;i < n;i++){
		mx = max(mx,a[i]-mn);
		mn = min(mn,a[i]);
	}

	map<int,int> cnt;
	ll ans = 0;
	for(int i = 0;i < n;i++){
		ans += cnt[a[i]-mx];
		cnt[a[i]]++;
	}

	cout << ans << endl;
}
