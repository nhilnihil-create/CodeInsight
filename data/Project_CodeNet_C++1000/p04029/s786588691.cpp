#include <stdio.h>

int main() {
    int anak;
    int jumlah = 0;
    scanf("%d", &anak);
    for (int i = 1; i <= anak; i++) {
        jumlah += i;
    }
    printf("%ld", jumlah);
}