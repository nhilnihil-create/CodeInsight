#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x,y,a,sum;
    cin>>n>>k>>x>>y;

    sum = 0;
    if(n>k)
    {
        a = n-k;
        while(k--)
            sum += x;
        while(a--)
            sum += y;
    }
    else
    {
        while(n--)
            sum += x;
    }
    cout<<sum<<endl;
}
