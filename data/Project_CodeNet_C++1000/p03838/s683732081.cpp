#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second

ll x, y;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x >> y;
	
	ll ret = 0;
	if(y <= 0){
		if(x <= y) ret = y - x;
		else if(x < 0) ret = 2 + x - y;
		else if(x <= -y) ret= 1 - x - y;
		else ret = 1 + y + x;
	}else{
		if(x < 0) ret = 1 + x + y + 2 * (max(x, -y) - x);
		else if(x <= y) ret = y - x;
		else ret = 2 - x + y + 2 * (x - min(x, y));
	}
	
	cout << ret << endl;

	return 0;
}