#include<cstdio>
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    
    int t = a+b;
    
    if(t>=24)
    {
        t=t-24;
    }
    
    printf("%d",t);
    
    
    
}


