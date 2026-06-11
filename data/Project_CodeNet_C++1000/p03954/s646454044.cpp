#include<bits/stdc++.h>
#define F first
#define S second
#define LL long long
#define PB push_back
#define MP make_pair
#define I insert

const LL N = 2e5+5, mod = 1000000007;

using namespace std;

LL n, m, i, j, k, l, r, t, ans, nn;
LL a[N], b[N], c[N];
LL xe[N*3];

void upd ( LL x ) {
	while ( x <= N ) {
		xe[x]++;
		x += (x & -x);
	}
}
 
LL get ( LL x ) {
	LL k = 0;
	while ( x > 0 ) {
		k += xe[x];
		x -= (x & -x);
	}
	return k;
}

int main(){
	cin >> n;
	for ( i = 1; i < 2*n; ++i ){
		cin >> a[i];
		b[i] = a[i];
	}
	sort ( b + 1, b + 2 * n );
	for ( LL ww = 18; ww >= 0; --ww ){
		k = ans + ( 1 << ww );
		if ( k >= 2 * n ) continue;
		for ( i = 1; i < 2 * n; ++i ){
			if ( a[i] >= b[k] ) c[i] = 1;
			else c[i] = 0;
		}
		for ( l = n; l > 1; --l ){
			if ( c[l] == c[l-1] ) break;
		}
		for ( r = n; r < 2 * n - 1; ++r ){
			if ( c[r] == c[r+1] ) break;
		}
		//cout << k << " " << b[k] << " " << l << " " << r << "  " << c[l] << "->";
		if ( l == 1 && r == 2 * n - 1 ) l = r = n - (1 - n%2);
		if ( l == 1 ) l = r;
		if ( r == 2 * n - 1 ) r = l;
		if ( n - l > r - n ) l = r;
		if ( c[l] ) ans = k;
		//cout << c[l] << endl;
	}
	cout << b[ans] << endl;
	return 0;
}
 
/**/
//      IIIIIIIII      OOOOO             A          NN        N    EEEEEEEEEE
//          I         O     O           A A         N N       N    E
//          I        O       O         A   A        N  N      N    E
//          I        O       O        A     A       N   N     N    E
//          I        O       O       AAAAAAAAA      N    N    N    EEEEEEEE
//          I        O       O      A         A     N     N   N    E
//          I        O       O     A           A    N      N  N    E
//          I         O     O     A             A   N       N N    E
//      IIIIIIIII      OOOOO     A               A  N        NN    EEEEEEEEEE ___ KAPANADZE