#include<cstdio>
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    int x,a,b;
    cin >> x >> a >> b;
    int num = 0;
    int num1 = 0;
    
    if(x>a)
    {
        num = x-a;
    }
    else
    {
        num = a-x;
    }
    
    if(x>b)
    {
        num1 = x - b;
    }
    else
    {
        num1 = b - x;
    }
    
    if(num > num1)
    {
        cout << "B";
    }
    else
    {
        cout << "A";
    }
    
    
    
}


