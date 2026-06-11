/* ex2_3
   YSK722 */

#include <stdio.h>

int main(void){
    int size, white;
    scanf("%d", &size);
    scanf("%d", &white);
    if(size < 1 || 100 < size){
        return 1;
    }
    if(white < 0 || size * size < white){
        return 1;
    }
    printf("%d\n", size * size - white);
    return 0;
}
