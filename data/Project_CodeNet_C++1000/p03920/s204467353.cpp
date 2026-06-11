#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define ALL(v) v.begin(), v.end()
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll N ; cin >> N ;
	if (N==1 || N==2) {
		cout << N << endl ;
		return 0 ;
	}
	vector<int> A ;
	ll sum = 0 ;
	FOR(i, 1, N) {
		sum += i ;
		A.push_back(i) ;
		if(sum >= N) break ;
	}
	if (sum==N) {
		for(auto n:A) cout << n << endl ;
	} else {
		ll rest = sum - N ;
		ll M = A.size() ;
		vector<int> B ;
		FOR(i, 1, M+1) {
			//cout << A[M-i] << rest << endl ;
			if (A[M-i] > rest) {
				B.push_back(A[M-i]);
			} else {
				rest -= A[M-i] ;
			}
		}
		sort(ALL(B)) ;
		for(auto n:B) cout << n << endl ;
	}
}