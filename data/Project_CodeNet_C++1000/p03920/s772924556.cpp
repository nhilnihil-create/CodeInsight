

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

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

typedef long long ll;

using namespace std;

int main() {
	
	int x;
	cin >> x;

	int limit = 0;
	for (int i = 1; i <= x; i++) {
		if (2*x <= (i*i + i)) {
			limit = i;
			break;
		}
	}

	int excludenum = limit*(limit + 1) / 2 -x;

	for (int i = 1; i <= limit; i++) {
		if (i != excludenum) {
			cout << i << endl;
		}
	}
}