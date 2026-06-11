#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;


int main() {
	ll N, L; cin >> N >> L;
	vector<ll> a(N);
	ll id = 1e8;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (i != 0 && a[i - 1] + a[i] >= L)id = i;
	}

	if(id==1e8)cout << "Impossible" << endl;
	else {
		cout << "Possible" << endl;
		for (int i = 1; i < id; i++) {
			cout << i << endl;
		}
		for (int i = N - 1; i > id; i--) {
			cout << i << endl;
		}
		cout << id << endl;
	}

}
