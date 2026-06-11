#include <stdio.h>

int main() {
	int ZxZ, CandChi = 0;
	scanf("%d", &ZxZ);
	for (int o = 0; o <= ZxZ; o++) {
		CandChi += o;
	}
	printf("%d", CandChi);
	return 0;
}