#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,x;
long long solve(long long a,long long b)
{
    if(a<b)swap(a,b);if(!b)return -a;
    return 2*(a-a%b)+solve(b,a%b);
}
int main()
{
    scanf("%lld%lld",&n,&x);
    cout<<n+solve(n-x,x)<<endl;
}