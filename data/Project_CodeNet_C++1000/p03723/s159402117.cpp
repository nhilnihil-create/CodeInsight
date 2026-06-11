#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e5 + 5;
const int inf = 1000000000;
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338; // double PI = 4*atan(1);



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
	//ifstream cin (".in");
	//ofstream cout (".out");
    int A, B, C;
	cin >> A >> B >> C;
	int it = 0;
	while (A%2==0 && B%2==0 && C%2==0) {
		int a = A/2, b = B/2, c = C/2;
		A = b+c;
		B = a+c;
		C = a+b;
		++it;
		if (it > 1000000) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << it << endl;
}



