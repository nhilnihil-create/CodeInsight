#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n%10==9 || n/10==9){
        printf("Yes");
    }
    else{
        printf("No");
    }
}
