#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin>> a>>b;
    int d = a+b;
    int r = d %2 ;
    if (a > 0 && b > 0)
    {
        cout<<"Positive";
    }
    else if (a < 0 && b < 0)
    {
        if (r==0)
        {
            cout<<"Negative";
        }
        else
        {
            cout<<"Positive";
        }
    }
    else if (a < 0 && b > 0)
    {
        cout<<"Zero";
    }
    else if (a > 0 && b < 0)
    {
        cout<<"Zero";
    }
    
    
    
    return 0;
}
