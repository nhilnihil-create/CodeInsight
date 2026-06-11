#include<bits/stdc++.h>
using namespace std;
int a[30050];
int main(){
    long long n,x;
    scanf("%lld%lld",&n,&x);
    printf("%lld\n",3ll*(n-__gcd(n,x)));
    return 0;
}