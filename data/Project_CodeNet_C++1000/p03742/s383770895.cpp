#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;

int main(){
	//freopen("stl.gir", "r", stdin);
	
	ll a, b;
	cin >> a >> b;
	if (abs(a-b) < 2) cout << "Brown" << endl;
	else cout << "Alice" << endl;
}