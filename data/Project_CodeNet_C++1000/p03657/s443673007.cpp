#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int a,b;
    cin>>a>>b;
    if(a%3==0){
        printf("Possible\n");
    }else if(b%3==0){
        printf("Possible\n");
    }else if((a+b)%3==0){
        printf("Possible\n");
    }else{
        printf("Impossible\n");
    }
    return 0;
}