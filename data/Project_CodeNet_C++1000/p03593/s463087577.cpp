#include <bits/stdc++.h>
using namespace std;

const int maxN = 110;

int C[4];
int cnt[26];
char str[maxN];

int main (){
	int h, w, i, j, ans = 0;
	scanf("%d%d", &h, &w);
	for(i = 0; i < h; ++i){
		scanf("%s", str);
		for(j = 0; j < w; ++j)
			++cnt[str[j] - 'a'];
	}
	for(i = 0; i < 26; ++i) ++C[cnt[i] % 4];
	if(h % 2 == 0){
		if(w % 2 == 0)
			ans = !C[1] && !C[2] && !C[3];
		else
			ans = !C[1] && !C[3] && (C[2] <= h / 2);
	}
	else{
		if(w % 2 == 0)
			ans = !C[1] && !C[3] && (C[2] <= w / 2);
		else
			ans = C[1] == 1 && !C[3] && (C[2] <= w / 2 + h / 2);
	}
	puts(ans ? "Yes" : "No");
	return 0;
}
