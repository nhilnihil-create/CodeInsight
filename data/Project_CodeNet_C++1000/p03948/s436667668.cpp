

#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<queue>
#include<list>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<cstdio>
#include <iomanip>

#define rep(i,b) for(int i=0;i<b;i++)
#define rrep(i,a,b) for(int i=a;i<=b;i++)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

using namespace std;
typedef long long ll;

//解説で説明された方法でACしてみよう!
//N=10^5 O(n^2)は使えない。
int main() {
	
	int n, t; cin >> n >> t;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> mx(n-1);

	int tempmax = -1;
	for (int i = n - 1; i >= 1; --i) {
		
		if (tempmax < a[i]) {
			tempmax = a[i];
		}

		mx[i - 1] = tempmax;
	}
	
	int mincost = 1 << 30;
	int maxdiff = -1;
	int cnt = 0;


	for (int i = 0; i < n-1; i++) {
		int diff = mx[i] - a[i];
		
		if (diff > maxdiff) {
			maxdiff = diff;
			cnt = 1;
		}
		else if (diff==maxdiff) {
			++cnt;
		}
	}

	cout << cnt << endl;

}
