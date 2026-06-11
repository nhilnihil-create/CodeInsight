#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int i=1,counter{0},flag = 0;
    while(n--)
    {
        i = arr[i-1];
        counter++;
        if(i == 2)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        cout<<counter<<endl;
    else
    {
        cout<<"-1"<<endl;
    }
    
    return 0;
}