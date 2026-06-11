//Created by Young Charlie
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m; cin>>n>>m;
	cout<<(n % 3 == 0 || m % 3 == 0 || ((n + m) % 3 == 0) ? "Possible\n" : "Impossible\n");
}
