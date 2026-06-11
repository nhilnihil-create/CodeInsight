#include <bits/stdc++.h>
using namespace std;

string s;
long long n,r,sd[15];

long long bts(long long a,long long b,string s)
{
    long long br=0,d=1;
    for(int i=b;i>=a;i--)
    {
        br+=(s[i]-'0')*d;
        d*=10;
    }
    return br;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>s;
    n=s.size();

    sd[0]=1;
    for(int i=1;i<15;i++)
        sd[i]=sd[i-1]*2;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            long long f1,f2;
            if(i==0)
                f1=1;
            else
                f1=sd[i-1];
            if(j==n-1)
                f2=1;
            else
                f2=sd[n-1-j-1];
            r+=bts(i,j,s)*f1*f2;
        }
    }

    cout<<r<<endl;

    return 0;
}
