#include <bits/stdc++.h>
using namespace std;

int main(){
int h, w, d; scanf("%d%d%d", &h, &w, &d);
if(d & 1){ for(int i = 0; i < h; i++, puts("")) for(int j = 0; j < w; j++) putchar("RB"[(i + j) & 1]); }
else{ for(int i = 0; i < h; i++, puts("")){ for(int j = 0; j < w; j++){ int k = min(i % d, d - i % d); int p = j % d; int l = j / d + i / d; l &= 1; int q = (i % d > d / 2); putchar("RGBY"[l ^ (p < k ? 2 : p >= d - k ? 3 : q)]); } }}
}