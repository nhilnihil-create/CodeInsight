#include <bits/stdc++.h>
using namespace std;

const int maxN = 510;
const char ch[8] = "RYGB";

int h, w;
char str[maxN][maxN];

inline void mark(int x, int y, int k){
	if(0 <= x && x < h && 0 <= y && y < w)
		str[x][y] = ch[k];
}

int main (){
	int d, i, j;
	scanf("%d%d%d", &h, &w, &d);
	if(d & 1){
		for(i = 0; i < h; ++i){
			for(j = 0; j < w; ++j)
				printf("%c", ch[(i + j) & 1]);
			puts("");
		}
	}
	else{
		if(d & 2){
			for(i = 0; i < h; ++i){
				for(j = 0; j < w; ++j)
					printf("%c", ch[((i & 3) + (j & 2)) & 3]);
				puts("");
			}
		}
		else{
			int s, t, p, q, k, dm = d / 2;
			for(p = -1; p <= max(0, h / dm) + 1; ++p){
			for(q = -1; q <= max(0, w / dm) + 1; ++q){
				s = p * dm, t = q * d;
				if(p & 1) t += dm;
				k = (p & 1) + ((p / 2 + q) & 1) * 2;
				for(i = 0; i < dm; ++i){
					for(j = 0; j < dm - i; ++j){
						mark(s + i, t + dm - j - 1, k);
						mark(s + i, t + dm + j, k);
						mark(s - i, t + dm - j - 1, k);
						mark(s - i, t + dm + j, k);
					}
				}
			}}
			for(i = 0; i < h; ++i) puts(str[i]);
		}
	}
	return 0;
}