#include <stdlib.h>
#include <stack>
#include <iostream>
using namespace std;


#define REP(i,n) for(long i=0; i<(long)(n); ++i)
#define FOR(i,k,n) for(long i=(k);i<(long)(n);++i)

int main(){
	long n;

	cin >> n;
	stack<long> x;
	long long int ans = 1;
	const long long int mod = 1000000007;
	REP(i, n){
		long y;
		cin >> y;
		x.push(y);
		if(y < 2*x.size()-1){
			ans = ans * x.size() % mod;
			x.pop();
		}
	}
	REP(i, x.size()){
		ans = ans * (i+1) % mod;
	}
	cout << ans<< endl;
	return 0;
}
