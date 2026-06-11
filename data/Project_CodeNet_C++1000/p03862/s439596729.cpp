#include<bits/stdc++.h>
using namespace std;
const long long int N=100090;
long long ara[N];
int main()
{
    long long int n,x,p,cnt=0;
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>ara[i];
    for(int i=0;i<n-1;i++)
    {
        p=ara[i]+ara[i+1];
        if(p>x)
        {
            cnt+=(p-x);
            ara[i+1]=ara[i+1]-min(ara[i+1],(p-x));
        }
    }
    cout<<cnt<<endl;
    return 0;
}
