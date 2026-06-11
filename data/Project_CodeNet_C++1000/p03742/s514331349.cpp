#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    if (abs(a-b)>1){
        printf("Alice");
    }
    else printf("Brown");
    return 0;
}