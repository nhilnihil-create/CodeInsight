#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[3];
int main(){
    scanf("%lld %lld %lld", a, a+1, a+2);
    sort(a, a+3);
    if(a[2]%2==0 || a[1]%2==0 || a[0]%2==0)
        printf("0\n");
    else 
        printf("%lld\n",a[0]*a[1]);
    //system("pause");
    return 0;
}