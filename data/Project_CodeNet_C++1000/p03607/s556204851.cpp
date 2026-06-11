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
#include <bitset>
#include <set>
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	ll k;
	set<ll> st;
	for(ll i=0; i<n; i++){
		cin >> k;
		auto it = st.find(k);
		if(it == end(st))
			st.insert(k);
		else
			st.erase(k);
	}
	cout << st.size();
	return 0;
}