#include<stdio.h>
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int distance_1 = b - a;
    int distance_2 = c - a;
    if(distance_1 < 0){
        distance_1 = distance_1 * -1;
    }
    if(distance_2 < 0){
        distance_2 = distance_2 * -1;
    }
    if(distance_2 < distance_1){
        printf("B\n");
    }
    else{
        printf("A\n");
    }
    return 0;
}