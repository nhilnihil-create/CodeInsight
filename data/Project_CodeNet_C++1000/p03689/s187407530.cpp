#include <cstdio>
int H, W, h, w;
int main() {
	scanf("%d%d%d%d", &H, &W, &h, &w);
	if(H%h + W%w == 0) return !puts("No");
	puts("Yes");
	for(int i=0; i<H; i++, puts("")) for(int j=0; j<W; j++)
		if(H%h) printf("%d ", i%h ? -1000 : 1000*(h-1)-1);
		else printf("%d ", j%w ? -1000 : 1000*(w-1)-1);
	return 0;
}