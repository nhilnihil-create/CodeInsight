#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,odd=0,even=0,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
       long long a;
       cin>>a;
       if((a&1)==1)
            even++;
        else
            odd++;
    }
    if(even%2==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

