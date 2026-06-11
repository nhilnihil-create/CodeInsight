#include <stdio.h>

int main() {
	int count = 0;
	char Zx[14], Yz[14] = {};
	scanf("%s", &Zx);
	
	for (int u = 0; Zx[u] != '\0'; u++) {
		if (Zx[u] == '0') {
			Yz[count] = '0';
			count++;
		}
		else if (Zx[u] == '1') {
			Yz[count] = '1';
			count++;
		}
		else if (count != 0) {
            if (Zx[u] == 'B') {
                Yz[count - 1] = '0';
                count -= 1;
            }
    	}
	}
	Yz[count] = '\0';
    printf("%s", Yz);
	return 0;
}