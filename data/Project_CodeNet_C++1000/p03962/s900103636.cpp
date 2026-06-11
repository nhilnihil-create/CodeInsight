#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c;
	set<int> s;
	cin >> a >> b >> c;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	cout << (int)s.size();
}