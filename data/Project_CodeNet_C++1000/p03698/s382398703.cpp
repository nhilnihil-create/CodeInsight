/*https://atcoder.jp/contests/abc063/tasks/abc063_b*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	vector <char> v;
	char c;
	int count = 0;
	while (cin >> c)
		v.push_back(c), count++;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	if (v.size() == count)
		cout << "yes";
	else
		cout << "no";
}