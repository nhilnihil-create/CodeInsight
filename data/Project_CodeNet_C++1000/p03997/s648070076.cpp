#include <iostream>
using namespace std;

int main()
{
    int a,b,h,t;
    cin >> a >> b >> h;

    if(a > b){
        t = a;
        a = b;
        b = t;
    }

    int  area;
    area = a*h + (b-a)*h/2;
    cout << area;
 
}


