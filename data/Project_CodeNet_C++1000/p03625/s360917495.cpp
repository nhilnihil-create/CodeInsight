#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,j,k,l,a,b,d,s,c;
    cin>>n;
    long long arr[n+10];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr+0,arr+n);
    s=1;
    c=0;
    for(i=n-1; i>=0; i--)
    {
        if(arr[i]==arr[i-1])
        {
            s*=arr[i];
            i--;
            c++;
            if(c==2)
            {
                break;
            }
        }
    }
    if(c!=2)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<s<<endl;
    }

    return 0;

}
