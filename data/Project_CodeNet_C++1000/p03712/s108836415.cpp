#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int h,w;
    cin>>h>>w;
    string* arr = new string[h];
    for(int i=0;i<h;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<w+2;i++)
    {
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<h;i++)
    {
        cout<<"#";
        cout<<arr[i];
        cout<<"#";
        cout<<endl;
    }
    for(int i=0;i<w+2;i++)
    {
        cout<<"#";
    }
}