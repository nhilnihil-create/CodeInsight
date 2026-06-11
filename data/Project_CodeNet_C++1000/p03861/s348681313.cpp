#include <iostream>
using namespace std;
int main(){
    long long a, b, x, tmp;
    cin >> a >> b >> x;
    if(a%x==0&&b%x==0){
        printf("%lld\n",b/x-a/x+1);
    }else if(a%x==0){
        tmp = b%x;
        b -= tmp;
        printf("%lld\n",b/x-a/x+1);
    }else{
        tmp = a%x;
        a += x-tmp;
        tmp = b%x;
        b -= tmp;
        printf("%lld\n",b/x-a/x+1);
    }
    return 0;
}