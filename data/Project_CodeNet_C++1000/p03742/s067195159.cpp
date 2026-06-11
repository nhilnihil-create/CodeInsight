#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll x, y;
	cin >> x >> y;
	if (abs(x - y) <= 1)
		cout << "Brown" << endl;
	else
		cout << "Alice" << endl;

}