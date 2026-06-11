#include<iostream>
using namespace std;
int main()
{
    char c[12];
    for(int i=0;i<12;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<4;i++)
    {
        cout<<c[i];
    }
    cout<<" ";
    for(int i=4;i<12;i++)
    {
        cout<<c[i];
    }
    cout<<endl;
    return 0;
}