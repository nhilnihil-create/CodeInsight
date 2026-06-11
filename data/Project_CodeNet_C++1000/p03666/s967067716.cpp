#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

namespace std{
	template<>
	struct hash<P>{
		size_t operator()(const P &x) const{
			return hash<llong>()(x.first) ^ (hash<llong>()(x.second) << 1);
		}
	};
}

int main(){
	llong N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;

	bool check = false;
	N--;
	for(int i = 0; i < N; i++){
		llong mini = A + C*i - D*(N-i);
		llong maxi = A + D*i - C*(N-i);
		if(mini <= B && B <= maxi)
			check = true;
	}

	if(check)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}