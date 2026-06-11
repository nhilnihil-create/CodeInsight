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
	char a, b;
	cin >> a >> b;
	if(a == 'H' && b == 'H') puts("H");
	else if(a == 'D' && b == 'H') puts("D");
	else if(a == 'H' && b == 'D') puts("D");
	else if(a == 'D' && b == 'D') puts("H");

    return 0;
}

