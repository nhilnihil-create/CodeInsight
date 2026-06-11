#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	bool flag = true;
	int low = 1e8, up = 0;
	map<int, int> mp;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		mp[a[i]]++;
		low = min(low, a[i]);
		up = max(up, a[i]);
	}

	if (mp[low] + mp[up] < N || up - low>=2)cout << "No" << endl;
	else if (mp[low] == N) {
		//cout<<"mp[low]==N" << endl;
		if (a[0] == N - 1)cout << "Yes" << endl;
		else if (N >= 2 * a[0])cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	else {
		if (N - mp[low] >= 2 * (up - mp[low]) && mp[low] < up)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
}
