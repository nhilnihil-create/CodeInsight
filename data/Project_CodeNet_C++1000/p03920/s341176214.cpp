#include<cstdio>
int main(void){
	int n;
	int a;
	scanf("%d", &n);
	for (int i = 1; i<=n+1; i++){
		if (2 * n<i*(i + 1)){
			a = n - (i*(i - 1) / 2);
			for (int j = 1; j<i; j++){
				if (j>i - a - 1)printf("%d\n", j + 1);
				else printf("%d\n", j);
			}
			return 0;
		}
	}
	return 0;
}