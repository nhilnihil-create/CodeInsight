#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long a[5];
    cin>>a[1]>>a[2]>>a[3];
    sort(a+1,a+4);
    if(a[1]==5&&a[2]==5&&a[3]==7)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}