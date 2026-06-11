#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
ll n,a,b;
int main(){
    scanf("%lld%lld%lld",&n,&a,&b);
    if (n>1&&b>=a||n==1&&a==b) printf("%lld\n",(n-2)*(b-a)+1);
        else puts("0");
}