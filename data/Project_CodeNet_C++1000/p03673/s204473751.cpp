#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	vector<ll> a(t);
	for(auto &x : a)
		cin >> x;
	if(t&1){
		for(ll i=t-1; i>=0; i-=2)
			cout << a[i] << " ";
		for(ll i=1; i<t; i+=2)
			cout << a[i] << " ";
	}
	else{
		for(ll i=t-1; i>=0; i-=2)
			cout << a[i] << " ";
		for(ll i=0; i<t; i+=2)
			cout << a[i] << " ";
	}
	return 0;
}