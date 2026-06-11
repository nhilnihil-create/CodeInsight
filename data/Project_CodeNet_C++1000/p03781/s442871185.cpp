#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll x;
int main()
{scanf("%lld",&x);
int sum=0;
    for(int i=1;;i++)
       {sum+=i;
           if(sum>=x)
       {
           printf("%d\n",i);
          break;
       }
}
return 0;
}
