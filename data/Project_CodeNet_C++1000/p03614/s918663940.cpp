/*
▄███████▀▀▀▀▀▀███████▄
░▐████▀▒ЗАПУСКАЕМ▒▀██████▄
░███▀▒▒▒▒▒ДЯДЮ▒▒▒▒▒▒▀█████
░▐██▒▒▒▒▒▒БОГДАНА▒▒▒▒▒████▌
░▐█▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒████▌
░░█▒▄▀▀▀▀▀▄▒▒▄▀▀▀▀▀▄▒▐███▌
░░░▐░░░▄▄░░▌▐░░░▄▄░░▌▐███▌
░▄▀▌░░░▀▀░░▌▐░░░▀▀░░▌▒▀▒█▌
░▌▒▀▄░░░░▄▀▒▒▀▄░░░▄▀▒▒▄▀▒▌
░▀▄▐▒▀▀▀▀▒▒▒▒▒▒▀▀▀▒▒▒▒▒▒█
░░░▀▌▒▄██▄▄▄▄████▄▒▒▒▒█▀
░░░░▄██████████████▒▒▐▌
░░░▀███▀▀████▀█████▀▒▌
░░░░░▌▒▒▒▄▒▒▒▄▒▒▒▒▒▒▐
░░░░░▌▒▒▒▒▀▀▀▒▒▒▒▒▒▒▐
 
*/
#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <iomanip>
#include <random>


using namespace std;
  


#define ll long long
#define ld long double
#define null NULL
#define prev prev228
#define next next228
#define index index228
#define count count228


const int N = 100 * 1000 + 228;


int a[N];

int n;


inline bool bad(int i) {
	return i == a[i];
}


signed main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int i = 1;
	int res = 0;
	while (i <= n) {
		int j = i;
		if (a[i] != i) {
			++i;
			continue;
		}
		while (j + 1 <= n && bad(j + 1)) {
			++j;
		}
		int len = j - i + 1;
		res += (len + 1) / 2;
		i = j + 1;
	}
	printf("%d\n", res);
	return 0;
}




