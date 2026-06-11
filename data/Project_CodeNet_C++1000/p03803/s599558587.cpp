#include <bits/stdc++.h>
using namespace std;
#define ar array
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const ll mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	vector<int> xs { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1 };

	int posa = 0, posb = 0;
	for(int i = 0; i < xs.size(); i++) {
		if(xs[i] == a) posa = i;
		if(xs[i] == b) posb = i;
	}
	cout << (posa < posb ? "Bob" : (posa > posb ? "Alice" : "Draw")) << "\n";
    return 0;
}

