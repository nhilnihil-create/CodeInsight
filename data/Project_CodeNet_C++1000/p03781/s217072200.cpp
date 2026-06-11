#include <iostream>

using namespace std;
int X;
int main()
{
    cin>>X;
    int s = 0, t = 0;
    while(s<X){
        t++;
        s+=t;
    }
    cout<<t;
    return 0;
}
