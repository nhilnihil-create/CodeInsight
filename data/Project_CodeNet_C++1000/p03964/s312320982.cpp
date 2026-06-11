#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int n;
	cin >> n;
	vector<P> a(n);
	ll T,A;
	for(int i = 0; i < n; i++) {
		cin >> T >> A;
		a[i] = mp(T,A); 
	}
	ll z = 1,B = 1;
	for(int i = 0; i < n; i++) {
		ll x = max((a[i].fs + z - 1)/a[i].fs,(a[i].sc + B - 1)/a[i].sc);
		z = x * a[i].fs;
		B = x * a[i].sc;
	}
	cout << z+B << endl;
	// for(int i = 1; i < n; i++) {
	// 	ll lb = 0;
	// 	ll ub = (1<<19) - 1;
	// 	while(ub - lb > 1){
	// 		ll mid = (lb + ub)/2;
	// 		if ((a[i - 1].fs <= a[i].fs * mid) && (a[i - 1].sc <= a[i].sc * mid)){
	// 			ub = mid;
	// 		}
	// 		else{
	// 			lb = mid;
	// 		}

	// 		// cout << a[i].fs << ' ' << a[i].sc << endl;
	// 		// cout << mid <<endl;
	// 	} 
	// 	a[i].fs*= ub;
	// 	a[i].sc *= ub;
	// 	// cout << a[i].fs << ' ' << a[i].sc << endl;
	// }
	// cout << a[n - 1].fs + a[n - 1].sc << endl;
	return 0;
}