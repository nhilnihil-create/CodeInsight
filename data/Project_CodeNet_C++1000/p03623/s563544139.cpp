#include <stdio.h>
#include <math.h>
int main() {
	int Zj, Zk, Zl;
	scanf("%d %d %d", &Zj, &Zk, &Zl);
	abs(Zj - Zk) < abs(Zj - Zl) ? printf("A") : printf("B");
	return 0;
}