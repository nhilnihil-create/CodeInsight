#include<cstdio>
#include<iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    int a;
    cin >> a;
    
    int d = a/100;
    int e = (a%100)%10;
    
    if(d==e)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    
}


