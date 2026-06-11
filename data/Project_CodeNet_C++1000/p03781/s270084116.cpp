#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll sum=0;
    for(int i=1;;i++)
    {
        sum+=i;
        if(sum>=n)
        {
            cout<<i<<endl;
            return 0;
        }
    }
}
