#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[3];
    int f=0;
    int s=0;
    for(int i=0;i<3;i++)
    {
        cin>>arr[i];
        if(arr[i]==5)
        {
            f++;
        }
        else if(arr[i]==7)
        {
            s++;
        }
    }
    if(f==2 && s==1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}