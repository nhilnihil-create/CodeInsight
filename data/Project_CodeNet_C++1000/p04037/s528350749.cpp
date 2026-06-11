#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

struct cmp {
	inline bool operator() (const int &i1, const int &i2)const {
		return i1 > i2;
	}
};

int a[1000005];
int main() {
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>a[i];
	sort(a + 1, a + 1 + n, cmp());
	for (int i = 1; i <= n; i++)
		if (i + 1 > a[i + 1]) {
			int j = 0;
			for (; a[j + i + 1] == i; j++);
			if ( ( (a[i] - i) & 1) || (j & 1) ) puts("First");
			else puts("Second");
			return 0;
		}
}