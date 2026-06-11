#include <iostream>
#include <cstdio>
using namespace std;

int k;
string a;
int main()
{
	int i, t;
	cin >> a >> k;
	for (i = 0; i < a.size() - 1; i++) {
		t = ('z' + 1 - a[i]) % 26;
		if (t <= k) k -= t, a[i] = 'a';
	}
    a[a.size() - 1] = (a[a.size() - 1] - 'a' + k) % 26 + 'a';
    cout << a << endl;
    return 0;
}