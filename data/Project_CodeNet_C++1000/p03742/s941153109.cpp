#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long X, Y; cin >> X >> Y;
	if (abs(X-Y) <= 1) printf("Brown\n");
	else printf("Alice\n");
}