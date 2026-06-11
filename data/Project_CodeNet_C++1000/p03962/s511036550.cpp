// ABC046A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	set<int> ans;

	ans.insert(a);
	ans.insert(b);
	ans.insert(c);

	cout << ans.size() << endl;

	return 0;
}
