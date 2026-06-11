#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    if(a+b>=10){
        printf("error\n");
    } else {
        printf("%d\n", a+b);
    }
    
    return 0;
}