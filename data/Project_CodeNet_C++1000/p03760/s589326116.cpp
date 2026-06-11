#include<bits/stdc++.h>
using namespace std;
#define int long long int 


int32_t main()
{
    string odd,even;
    cin>>even>>odd;
    for(int i=0;i<max(odd.size(),even.size());i++)
    {
        if(i<even.size())
        cout<<even[i];
        if(i<odd.size())
        cout<<odd[i];
    }
}