#include <bits/stdc++.h>

using namespace std;

int main(){
    int x , i ;

    scanf("%d",&x);

    int s = 0 ;
    for ( i = 0 ; s<x ; i++ ){
        s+=i;
    }
    printf("%d",i-1);

    return 0;
}
