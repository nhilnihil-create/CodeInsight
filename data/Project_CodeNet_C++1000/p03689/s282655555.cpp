#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int H, W, h, w;
	cin >> H >> W >> h >> w;
	cat cnt_max = 1LL * ((H-1)/h+1) * ((W-1)/w+1);
	cat cnt_min = 1LL * ((H-h)/h+1) * ((W-w)/w+1);
	if(cnt_max == cnt_min) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) {
		int s = (i % h) + (j % w);
		if(s > 0 && s < h-1+w-1) cout << "0";
		if(s == 0) cout << cnt_min+1;
		if(s == h-1+w-1) cout << -(cnt_min+2);
		cout << ((j == W-1) ? "\n" : " ");
	}
	return 0;
}

// look at my code
// my code is amazing
