#include <bits/stdc++.h> 
using namespace std; 
int gi() { 
	int res = 0, w = 1; 
	char ch = getchar(); 
	while (ch != '-' && !isdigit(ch)) ch = getchar(); 
	if (ch == '-') w = -1, ch = getchar(); 
	while (isdigit(ch)) res = res * 10 + ch - '0', ch = getchar(); 
	return res * w; 
} 
int N, cnt[2]; 
int main () {
#ifndef ONLINE_JUDGE 
    freopen("cpp.in", "r", stdin); 
#endif 
	N = gi(); 
	for (int i = 1; i <= N; i++) { 
		int x = gi() & 1; 
		if (x) { 
			if (cnt[x]) ++cnt[x ^ 1], --cnt[x]; 
			else ++cnt[x]; 
		} else ++cnt[x]; 
	} 
	if (cnt[0] && cnt[1]) puts("NO"); 
	else puts("YES"); 
    return 0; 
} 