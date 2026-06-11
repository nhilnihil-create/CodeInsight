#include <cstdio>

using namespace std;

int n, m, k;
char str[2][2];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	str[0][0] = 'R', str[0][1] = 'G';
	str[1][0] = 'B', str[1][1] = 'Y';
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int x = (i + j + m - 2) / k % 2, y = (i - j + m) / k % 2;
			printf("%c", str[x][y]);
		}
		printf("\n");
	}	
	
	return 0;
}