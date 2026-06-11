#include <cstdio>

int main(){
    int alice,bob;
    scanf("%d %d",&alice,&bob);
    if(alice==1){
        alice=14;
    }
    if(bob==1){
        bob=14;
    }
    if(alice>bob){
        printf("Alice");
    }
    else if(alice==bob){
        printf("Draw");
    }
    else{
        printf("Bob");
    }

}
