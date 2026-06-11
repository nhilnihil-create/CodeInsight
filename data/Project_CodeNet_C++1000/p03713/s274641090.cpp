#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#define PI 3.14159265359
typedef long long ll;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
using namespace std;


ll llmin(ll x, ll y){
	if (x < y) return x;
	return y;
}

ll llmax(ll x, ll y){
	if (x > y) return x;
	return y;
}

int main(){
	ll h, w;
	cin >> h >> w;

	if (h % 3 == 0 || w % 3 == 0){
		cout << 0 << endl;
		return 0;
	}

	ll ans = llmin(h, w); 

	for (int i = -1; i <= 1; i++){
		for (int j = -1; j <= 1; j++){
			ll a = (h/3+i)*w;
			ll b = (h-h/3-i)*(w/2+j);
			ll c = (h-h/3-i)*(w-w/2-j);
			ans = llmin(ans, llmax(a, llmax(b, c)) - llmin(a, llmin(b, c)));
		}
	}
	for (int i = -1; i <= 1; i++){
		for (int j = -1; j <= 1; j++){
			ll a = (w/3+i)*h;
			ll b = (w-w/3-i)*(h/2+j);
			ll c = (w-w/3-i)*(h-h/2-j);
			ans = llmin(ans, llmax(a, llmax(b, c)) - llmin(a, llmin(b, c)));
		}
	}
	cout << ans << endl;
	return 0;
}
