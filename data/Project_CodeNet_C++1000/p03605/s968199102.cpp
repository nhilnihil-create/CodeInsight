#include <iostream>

using namespace std;

int main()
{
    char a[2];
    cin>>a;
    if(a[0]=='9' || a[1]=='9')
        cout<<"Yes";//<<endl<<"The one's digit of "<<a<<" is 9.";
    else
        cout<<"No";//<<endl<<a<<" does not contain 9.";
    return 0;
}
