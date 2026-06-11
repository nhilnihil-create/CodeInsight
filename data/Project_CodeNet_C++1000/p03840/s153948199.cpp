#include <bits/stdc++.h>
using namespace std;

void solve(long long a_I, long long a_O, long long a_T, long long a_J, long long a_L, long long a_S, long long a_Z){
	long long res = 0;
	res = a_O + a_I / 2 * 2 + a_J / 2 * 2 + a_L / 2 * 2;

	long long c = a_I % 2 + a_J % 2 + a_L % 2;
	if(c == 3) {
		res += 3;
	} else if(c == 2 && a_I > 0 && a_J > 0 && a_L > 0) {
		res += 1;
	}
	cout << res << endl;
}

int main(){	
	long long a_I;
	long long a_S;
	long long a_O;
	long long a_Z;
	long long a_L;
	long long a_T;
	long long a_J;
	scanf("%lld",&a_I);
	scanf("%lld",&a_O);
	scanf("%lld",&a_T);
	scanf("%lld",&a_J);
	scanf("%lld",&a_L);
	scanf("%lld",&a_S);
	scanf("%lld",&a_Z);
	solve(a_I, a_O, a_T, a_J, a_L, a_S, a_Z);
	return 0;
}

