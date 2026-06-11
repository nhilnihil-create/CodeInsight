#include<bits/stdc++.h>
#define F first
#define S second
#define LL long long
#define PB push_back
#define MP make_pair
#define I insert
 
const LL N = 1e5+5, mod = 1000000007;
 
using namespace std;
 
LL n, m, i, j, k, l, r, t, ans, a[N];
vector < LL > v[N];

void go ( LL u, LL par = 0 ){
	for ( LL i = 0; i < v[u].size(); ++i ){
		if ( v[u][i] == par ) continue;
		go ( v[u][i], u );
		a[u] ^= (a[v[u][i]]+1);
	}
	//if ( u == 1 && v[u].size() == 1 || u != 1 && v[u].size() == 2 ) a[u]++;
}

int main(){
	cin >> n;
	for ( i = 1; i < n; ++i ){
		cin >> l >> r;
		v[l].PB(r);
		v[r].PB(l);
	}
	
	go(1);
	
	if ( a[1] ) cout << "Alice\n";
	else cout << "Bob\n";
	
	return 0;
}
 
/**/
//      IIIIIIIII      OOOOO             A          NN        N    EEEEEEEEEE
//          I         O     O           A A         N N       N    E
//          I        O        O         A   A        N  N      N    E
//          I        O       O        A     A       N   N     N    E
//          I        O       O       AAAAAAAAA      N    N    N    EEEEEEEE
//          I        O       O      A         A     N     N   N    E
//          I        O       O     A           A    N      N  N    E
//          I         O     O     A             A   N       N N    E
//      IIIIIIIII      OOOOO     A               A  N        NN    EEEEEEEEEE ___ KAPANADZE