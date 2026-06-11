#include<cstdio>
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    if(a>=b)
    {
        printf("%d",(b*c)+(d*(a-b)));
    }
    else
    {
        printf("%d",a*c);
    }
    
    
}


