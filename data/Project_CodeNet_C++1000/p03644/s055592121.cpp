#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int main()
{
    int n,ans=0,maxi=0;
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        int cntr=0;
        int num=i;
        while(num%2==0 && num>0)
        {
            cntr++;
            num/=2;
        }
        if(cntr>maxi)
        {
            maxi=cntr;
            ans=i;
        }
    }
    if(n==1)
        cout<<1;
    else
        cout<<ans;
    return 0;
}
