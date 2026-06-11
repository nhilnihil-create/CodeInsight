//arc071_d.cpp
//Sun Jan 12 19:04:15 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	ll n,m;
	cin >> n >> m;

	ll MAX = 1000000007;

	ll x[n];
	ll tate = 0;
	ll baset = 0;
	for (ll i=0;i<n;i++){
		cin >> x[i];
		if (i==0){
			baset = x[0];
		}
		x[i] = x[i] - baset;
		if (i>0){
			tate = (tate + (x[i]-x[i-1])*(n-i)*(i))%MAX;
		}
	}

	ll y[m];
	ll yoko = 0;
	ll basey = 0;
	for (ll i=0;i<m;i++){
		cin >> y[i];
		if (i==0){
			basey = y[0];
		}
		y[i] = y[i] - basey;
		if (i>0){
			yoko = (yoko + (y[i]-y[i-1])*(m-i)*(i))%MAX;
		}
	}

	ll ans = (tate*yoko)%MAX;

	cout << ans << endl;
}