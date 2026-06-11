#include <bits/stdc++.h>

using namespace std;

char ch[4] = {'R', 'Y', 'G', 'B'};
int n, m, d, sz;

int main()
{
	int i, j, x, y;
	
	scanf("%d%d%d", &n, &m, &d);
	
	if(d & 1){
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				printf("%c", ch[i + j & 1]);
			}
			printf("\n");
		}
	}
	else{
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				x = ((i - j + d * m * 4) / d % 4 + 4) % 4;
				y = (i + j + d * 2) / d % 4;
				if((x - y + 4) % 4 < 2) printf("%c", ch[(x + y) % 4]);
				else printf("%c", ch[(x + y + 2) % 4]);
			}
			printf("\n");
		}
	}
	
	return 0;
}