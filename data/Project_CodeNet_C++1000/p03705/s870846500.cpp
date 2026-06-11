#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a,b;
    scanf("%lld%lld%lld",&n,&a,&b);
    if(a==b)
       printf("1\n");
    else if(a>b)
      printf("0\n");
    else if(n==1)
      printf("0\n");
    else
      printf("%lld\n",(n-2)*(b-a)+1);
    return 0;
}
