#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int s[n+5];
    for(long long int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    long long int odd=0;
    long long int even=0;
    for(long long int i=0;i<n;i++)
    {
        if(s[i]%2!=0)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    if(odd%2==0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        if(n==1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
