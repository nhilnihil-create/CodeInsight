#include<iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;
    if(a % 10 == 9)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    else if(a / 10 == 9)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    else
    {
        cout<<"No"<<endl;
        return 0;
    }
}
