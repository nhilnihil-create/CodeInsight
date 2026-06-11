#include <iostream>
#include <bits/c++io.h>

using namespace std;

int main()
{
 int a,b,c;
 cin>>a>>b>>c;
 if(abs(a-b)>abs(a-c))
    cout<<"B"<<endl;
    else
        cout<<"A"<<endl;
}
