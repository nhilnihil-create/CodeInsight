#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;
    if(a+b >= 10) printf("error\n");
    else printf("%lld\n", a+b);
    return 0;
}