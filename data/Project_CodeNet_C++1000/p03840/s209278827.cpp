#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second

ll a, b, c;

ll sol1(ll x, ll y, ll z){
	ll ret = x - (x & 1);
	x &= 1;
	
	if(x && y && z) ret += 3, y--, z--;
	ret += y + z - (y & 1) - (z & 1);
	
	return ret;
}

ll sol2(ll x, ll y, ll z){
	ll ret = y + z - (y & 1) - (z & 1);
	y &= 1, z &= 1;
	
	if(x && y && z) ret += 3, x--;
	ret += x - (x & 1);
	
	return ret;
}

ll sol3(ll x, ll y, ll z){
	ll ret = min({x, y, z});
	x -= ret, y -= ret, z -= ret;
	ret *= 3;
	
	ret += x + y + z - (x & 1) - (y & 1) - (z & 1);
	
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll ret;
	
	cin >> a >> ret >> b >> b >> c;
	
	ret += max({sol1(a, b, c), sol2(a, b, c), sol3(a, b, c)});
	
	cout << ret << endl;

	return 0;
}