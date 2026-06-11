#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,k;
    cin>>n;
    long long a[n],freq[100005];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        freq[a[i]]++;
    }
    sort(a,a+n,greater<int>());
    long long x=0,y=0;
    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {x=a[i];
        break;}
    }
    for(j=i+2;j<n;j++)
    {
        if(a[j]==a[j-1])
        {
            y=a[j];
            break;
        }
    }
    cout<<x*y<<endl;

}
