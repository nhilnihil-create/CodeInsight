#include <stdio.h>

int main(){

    int jumlahAnak;
    int total=0;
    scanf("%d", &jumlahAnak);
    for(int i=1;i<=jumlahAnak;i++){
        total=total+i;
    }
    printf("%d", total);
    return 0;
}