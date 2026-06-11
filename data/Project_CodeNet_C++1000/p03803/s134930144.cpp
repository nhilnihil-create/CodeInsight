#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b;
	cin >> a >> b;
	if (a == b) cout << "Draw";
	else if (a == 1) cout << "Alice";
	else if (b == 1) cout << "Bob";
	else if (a > b) cout << "Alice";
	else cout << "Bob";
}