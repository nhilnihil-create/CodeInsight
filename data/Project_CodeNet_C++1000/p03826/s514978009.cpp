#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int r1 = a * b;
    int r2 = c * d;

    if(r1>=r2){
        cout<<r1;
    }
    else{
        cout<<r2;
    }
}
