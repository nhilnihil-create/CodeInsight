#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	ll x, y;
	cin >> x >> y;
	
	
	if( x == y) cout << 0;
	else if(-x == y) cout << 1;
	else if(x > 0 && y > 0){
		if(x < y) cout << y-x;
		else cout << x-y+2;
	}
	else if(x < 0 && y < 0){
		if(x < y) cout << y - x;
		else cout << 2 + x - y;
	}
	else if(x == 0){
		if( y > 0 ) cout << y;
		else cout << abs(y) + 1;
	}
	else if(y == 0){
		if(x > 0) cout << x +1;
		else cout <<  abs(x);
	}
	else cout << abs(abs(y) - abs(x)) + 1;

			

}
