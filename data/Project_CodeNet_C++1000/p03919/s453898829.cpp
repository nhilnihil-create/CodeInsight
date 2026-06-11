#include <bits/stdc++.h>

using namespace std;

char s[10];

int n, m;

int main(){
	while(~scanf("%d %d", &n, &m)){
		for(int i=1; i<=n; i++){
			for(int j=0; j<m; j++){
				scanf("%s", s);
				if(strcmp(s, "snuke") == 0){
					printf("%c%d\n", j+'A', i);
				}
			}
		}
	}
	return 0;
}
