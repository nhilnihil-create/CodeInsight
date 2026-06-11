#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	int t[100001];
	int a[100001];
	for(int i = 0; i < n; i++){
		cin >> t[i];
	}
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<pair<int, int> > ansv;
	for(int i = 0; i < n; i++){
		if(i > 0 && t[i] == t[i - 1]){
			ansv.push_back(make_pair(1, t[i] + 1));
		} else {
			ansv.push_back(make_pair(t[i], t[i] + 1));
		}
	}
	for(int i = n - 1; i >= 0; i--){
		int nowl = ansv[i].first;
		int nowr = ansv[i].second;
		if(i < n - 1 && a[i] == a[i + 1]){
			ansv[i] = make_pair(max(nowl, 1), min(nowr, a[i] + 1));
		} else {
			ansv[i] = make_pair(max(nowl, a[i]), min(nowr, a[i] + 1));
		}
	}
	long long int ans = 1;
	for(int i = 0; i < n; i++){
		ans =(ans * max(0, ansv[i].second - ansv[i].first)) % mod;
	}
	cout << ans << endl;
}