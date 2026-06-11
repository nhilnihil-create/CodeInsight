#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <assert.h>
#include <cmath>
#include <stack>
#include <deque>
#include <set>
#include <unordered_map>
#include <complex>
#include <fstream>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
const int mxn = 1e6+10;

long long gcdlike(long long a, long long b) {
	long long ret = a+b;
	if(a<b) swap(a, b);
	while(b) {
		long long q = a/b;
		long long r = a%b;
		ret+=2*q*b;
		if(r==0) ret-=b;
		a = b; b = r;
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n,x; cin>>n>>x;
	cout << gcdlike(n-x, x) << '\n';

	return 0;
}
//comparator function in sorting
//swapping arguments
//missing cases in dp
//dividing in modulo
//Beware of overflow and modulo
//Be mindful of overflow
//s is a matrix but forget
//length of ranges
//working with bit using ull