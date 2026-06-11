#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b;
    cin>>a>>b;
    if(a*b<=0)puts("Zero");
    else if(a>0&&b>0)puts("Positive");
    else if(a==b)puts("Negative");
    else if((b-a)&1)puts("Positive");
    else puts("Negative");
    return 0;
}
