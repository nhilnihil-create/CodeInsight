#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,sum=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        sum+=min(2*p,2*abs(p-k));
    }
    cout<<sum;
    return 0;
}

