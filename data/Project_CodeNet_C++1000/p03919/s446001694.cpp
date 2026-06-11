#include <cstdio>
#include <cstring>

int h, w;
char s[6];

int main(){
	scanf("%d %d", &h, &w);
	for(int i=0; i<h; ++i)
		for(int j=0; j<w; ++j){
			scanf("%s", s);
			if(strcmp(s, "snuke") == 0) printf("%c%d\n", 'A'+j, i+1);
		}
}