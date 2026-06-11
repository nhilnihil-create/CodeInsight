#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main()
{
    int w,a,b;

    cin >> w >> a >> b;

    if(b > a)
    {
        if(w+a > b )
            cout << "0";
        
        else
        {
            cout << b - w - a;
        }
        
    } 

    else
    {
        if(w + b > a )
            cout << "0";
        
        else
        {
            cout << a - w - b;
        }
    }
      
}

