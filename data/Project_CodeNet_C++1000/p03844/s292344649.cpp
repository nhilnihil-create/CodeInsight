#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b;
	char op;
	cin >> a >> op >> b;
	if (op == '+') cout << a+b;
	else cout << a-b;
}