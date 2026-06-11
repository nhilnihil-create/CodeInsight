#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	
	ll x, a, b;
	cin >> x >> a >> b;
	
	int c = b - a;
	if(c <= 0) cout << "delicious" << endl;
	else if(c <= x) cout << "safe" << endl;
	else cout << "dangerous" << endl; 
}