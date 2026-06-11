#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<unordered_set>
#include<unordered_map>
using namespace std;



int n;
vector<int> v;
int gcd(int a, int b) {
	if (a > b)swap(a, b);
	while (a) {
		swap(a, b);
		a %= b;
	}
	return b;
}
int main() {
	cin >> n;
	bool one = false;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			one = true;
		}
		v.push_back(a);
		sum += a - 1;
	}
	if (one == true) {
		if (sum & 1) {
			puts("First");
		}
		else {
			puts("Second");
		}
		return 0;
	}
	bool f = false;
	while (1) {
		f ^= true;
		vector<int> id;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] & 1) {
				id.push_back(i);
				
			}
			sum += v[i] - 1;
		}
		if (sum & 1) {
			if (f) {
				puts("First");
			}
			else {
				puts("Second");
			}
			return 0;
		}
		if (id.size() != 1) {
			if (f) {
				puts("Second");
			}
			else {
				puts("First");
			}
			return 0;
		}
		if (id.size() == 1) {
			if (v[id[0]] == 1) {
				if (f) {
					puts("Second");
				}
				else {
					puts("First");
				}
				return 0;
			}
			v[id[0]]--;
			int gc = 0;
			for (int i = 0; i < n; i++) {
				gc = gcd(gc, v[i]);
			}
			for (int i = 0; i < n; i++) {
				v[i] /= gc;
			}
			continue;
		}
	}
	return 0;
}