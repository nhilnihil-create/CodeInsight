#include<cstdio>
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    int x,a,b;
    cin >> x >> a >> b;
    
    if(b>a)
    {
        if(x>=b-a)
        {
            cout<< "safe";
        }
        else
        {
            cout << "dangerous";
        }
    }
    else if(a>b)
    {
        cout << "delicious";
    }
    else
    {
        cout << "delicious";
    }
    
    
    
}


