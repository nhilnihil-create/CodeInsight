#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

static bool query(ll x){
/*
	static const ll n = 1134;
	const bool a = (x <= n);
	const bool b = (to_string(x) <= to_string(n));
	return a == b;
*/
	cout << "? " << x << endl << flush;
	string s;
	cin >> s;
	return (s == "Y");
}

static int test(int k){
	ll lo = 1, hi = 9;
	for(int i = 1; i < k; ++i){
		lo *= 10;
		hi = (hi * 10 + 9);
	}
	return (query(lo) ? 1 : 0) | (query(hi) ? 2 : 0);
}

static int get_ndigits(){
	vector<int> t(12);
	for(int i = 1; i <= 11; ++i){ t[i] = test(i); }
	for(int i = 10; i >= 1; --i){
		if(t[i] != t.back()){
			if(t.back() == 3){
				return i + 1;
			}else{
				return i;
			}
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	const int m = get_ndigits();
	string answer(m + 1, '0');
	for(int i = 0; i < m; ++i){
		int lo = (i == 0 ? 1 : 0) + (i + 1 == m ? 0 : 1), hi = 10;
		while(lo < hi){
			const int mid = lo + (hi - lo) / 2;
			answer[i] = mid + '0';
			if(query(stoll(answer))){
				hi = mid;
			}else{
				lo = mid + 1;
			}
		}
		answer[i] = (i + 1 == m ? lo : (lo - 1)) + '0';
	}
	cout << "! " << answer.substr(0, m) << endl;
	return 0;
}

