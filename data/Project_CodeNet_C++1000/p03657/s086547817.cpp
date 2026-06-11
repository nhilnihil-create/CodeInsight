#include<bits/stdc++.h>
using namespace std;
int a,b,bj;
int main() 
{
    cin>>a>>b;
    if((!((a+b)%3))||(!(b%3))||(!(a%3)))puts("Possible");
    else puts("Impossible");
    return 0;
}