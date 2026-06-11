#include <iostream>
#include <cstdio>
#define N 150
using namespace std;

string a, mn, ans[N];

string f(string p, string q) {
	if (p == "") return q;
	if (p.size() != q.size()) return p.size() < q.size() ? p : q;
	return p < q ? p : q;
}

int main()
{
	int i, j;
	for (i = 'a'; i <= 'z'; i++) ans[i] = i;
	cin >> a;
	for (i = a.size() - 1; i >= 0; i--) {
		mn = "";
		for (j = 'a'; j <= 'z'; j++) mn = f(mn, ans[j]);
		ans[a[i]] = a[i] + mn;
	}
	mn = "";
	for (i = 'a'; i <= 'z'; i++) mn = f(mn, ans[i]);
    cout << mn << endl;
    return 0;
}