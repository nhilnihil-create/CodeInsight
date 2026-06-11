#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll x;
int main()
{scanf("%lld",&x);
    for(int i=1;i<=100000;i++)
        if(i+i*i-2*x>=0)
        {
            printf("%d\n",i);
            return 0;
        }
}
