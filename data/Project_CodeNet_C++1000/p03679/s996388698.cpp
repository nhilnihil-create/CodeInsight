#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(c>a+b)
    {
        cout<<"dangerous"<<endl;
    }
    else if(c<=b)
    {
        cout<<"delicious"<<endl;
    }
    else
    {
        cout<<"safe"<<endl;
    }
    return 0;
}
