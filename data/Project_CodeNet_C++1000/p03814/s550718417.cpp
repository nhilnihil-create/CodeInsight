#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	string s;
	cin >> s;
	int a = find(s.begin(),s.end(),'A') - s.begin();
	int z = find(s.rbegin(),s.rend(),'Z') - s.rbegin();
	z = (int) s.size() - z - 1;
	cout << z-a+1 << '\n';
	return 0;
}
