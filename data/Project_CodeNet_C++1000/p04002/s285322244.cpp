#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring> 
#include <cmath> 
#include <algorithm>
#include <map> 
using namespace std;
inline int gi() {
    register int data = 0, w = 1;
    register char ch = 0;
    while (!isdigit(ch) && ch != '-') ch = getchar(); 
    if (ch == '-') w = -1, ch = getchar();
    while (isdigit(ch)) data = data * 10 + ch - '0', ch = getchar(); 
    return w * data; 
} 
const int MAX_N = 1e5 + 5; 
const int dx[] = {-2, -1, 0}, dy[] = {-2, -1, 0}; 

int H, W, N; 
map<pair<int, int>, int> mp; 
int ans[20]; 
int main () { 
	H = gi(), W = gi(), N = gi(); 
	for (int i = 1; i <= N; i++) { 
		int x = gi(), y = gi(); 
		for (int j = 0; j < 3; j++) 
			for (int k = 0; k < 3; k++) { 
				int _x = x + dx[j], _y = y + dy[k]; 
				if (_x < 1 || _x + 2 > H || _y < 1 || _y + 2 > W) continue; 
				mp[make_pair(_x, _y)]++; 
			} 
	} 
	for (auto ite : mp) ans[ite.second]++, ans[0]--; 
	printf("%lld\n", 1ll * (H - 2) * (W - 2) + ans[0]); 
	for (int i = 1; i <= 9; i++) printf("%d\n", ans[i]); 
    return 0; 
} 