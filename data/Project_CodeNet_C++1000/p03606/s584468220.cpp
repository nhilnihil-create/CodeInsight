#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        sum+=(b-a+1);
    }
    cout<<sum<<"\n";
    return 0;
}
