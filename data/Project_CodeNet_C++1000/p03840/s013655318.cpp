#include <bits/stdc++.h>

#define int long long

using namespace std;

 main () {
	int i, o, t, j, l, s, z;
	cin >> i >> o >> t >> j >> l >> s >> z;
	int kol = 0;
	int kol1 = 0;                        
	kol1 += i / 2 * 4;
	kol1 += j / 2 * 4;
	kol1 += l / 2 * 4;
	if (i >= 1 && l >= 1 && j >= 1) {
		kol = 6;
		i --, l --, j --;
	}
	kol += i / 2 * 4;
	kol += j / 2 * 4;
	kol += l / 2 * 4 ;
	cout << max (kol, kol1) / 2 + o;
	return 0;
}                                                        