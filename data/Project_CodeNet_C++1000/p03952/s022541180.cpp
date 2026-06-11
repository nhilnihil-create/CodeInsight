#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

const int bound = 314159;
bool ok[bound];
bool flag = false;

int main(){
	int n, x; cin >> n >> x;
	if( n == 2 ){
		if( x == 1 || x == 3 ){
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl << 1 << endl << 2 << endl << 3 << endl; 
		}
		return 0;
	}
	if( 1 < x && x < 2*n-1 ){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
		return 0;
	}
	fill_n( ok, bound, true );
	if( x == 2*n-2 ) flag = true;
	if( flag ){
		ok[x-2] = ok[x] = ok[x+1] = ok[x-1] = false;
	} else {
		ok[x+2] = ok[x] = ok[x-1] = ok[x+1] = false;
	}
	vector<int> a;
	for( int k = 1; k <= 2*n-1; ++k ){
		if( ok[k] ) a.push_back(k);
	}
	auto itr = a.begin();
	for( int k = 1; k <= 2*n-1; ++k ){
		if( k == n-1 ){
			cout << ( (flag) ? x-2 : x+2 ) << endl;
		} else if( k == n ) {
			cout << x << endl;
		} else if( k == n+1 ){
			cout << ( (flag) ? x+1 : x-1 ) << endl;
		} else if( k == n+2 ){
			cout << ( (flag) ? x-1 : x+1 ) << endl;
		} else {
			cout << (*itr) << endl;
			++itr;
		}
	}
	return 0;
}