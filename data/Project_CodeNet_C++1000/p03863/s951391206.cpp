#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int ans = s.length() - (s.front() == s.back()?3:2);
	cout << (ans&1?"First":"Second") << '\n';
}
