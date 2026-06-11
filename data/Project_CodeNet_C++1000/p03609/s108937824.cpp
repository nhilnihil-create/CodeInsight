#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int x,t,result;
    cin >> x >>t;
    if(x>t){
        result=x-t;
    }
    else{
        result=0;
    }
    printf("%d",result);
    
}
