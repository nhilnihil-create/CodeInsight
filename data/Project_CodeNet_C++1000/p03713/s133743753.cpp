#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,sum1,sum2,sum3,val1,val2,val3,val4,mn=1e18;
    cin>>n>>m;
    for(long long i=1;i<n;i++)
    {
        vector<long long> v;
        sum1=m*i;
        if(m%2==0)
        {
            val1=m/2;
            val2=m/2;
            val3=n-i;
            val4=n-i;
            sum2=val1*val3;
            sum3=val2*val4;
        }
        else
        {
            val1=m/2+1;
            val2=m/2;
            val3=n-i;
            val4=n-i;
            sum2=val1*val3;
            sum3=val2*val4;
        }
        v.push_back(sum1);
        v.push_back(sum2);
        v.push_back(sum3);
        sort(v.begin(),v.end());
        mn=min(mn,v[2]-v[0]);
    }
    for(long long i=1;i<n-1;i++)
    {
        vector<long long> v;
        sum1=m*i;
        if((n-i)%2==0)
        {
            val1=m;
            val2=m;
            val3=(n-i)/2;
            val4=(n-i)/2;
            sum2=val1*val3;
            sum3=val2*val4;
        }
        else
        {
            val1=m;
            val2=m;
            val3=((n-i)/2)+1;
            val4=(n-i)/2;
            sum2=val1*val3;
            sum3=val2*val4;
        }
        v.push_back(sum1);
        v.push_back(sum2);
        v.push_back(sum3);
        sort(v.begin(),v.end());
        mn=min(mn,v[2]-v[0]);
    }
    for(long long i=1;i<m;i++)
    {
        vector<long long> v;
        sum1=n*i;
        if(n%2==0)
        {
            val1=n/2;
            val2=n/2;
            val3=m-i;
            val4=m-i;
            sum2=val1*val3;
            sum3=val2*val4;
        }
        else
        {
            val1=n/2+1;
            val2=n/2;
            val3=m-i;
            val4=m-i;
            sum2=val1*val3;
            sum3=val2*val4;
        }
        v.push_back(sum1);
        v.push_back(sum2);
        v.push_back(sum3);
        sort(v.begin(),v.end());
        mn=min(mn,v[2]-v[0]);
    }
    for(long long i=1;i<m-1;i++)
    {
        vector<long long> v;
        sum1=n*i;
        if((m-i)%2==0)
        {
            val1=n;
            val2=n;
            val3=(m-i)/2;
            val4=(m-i)/2;
            sum2=val1*val3;
            sum3=val2*val4;
        }
        else
        {
            val1=n;
            val2=n;
            val3=(m-i)/2+1;
            val4=(m-i)/2;
            sum2=val1*val3;
            sum3=val2*val4;
        }
        v.push_back(sum1);
        v.push_back(sum2);
        v.push_back(sum3);
        sort(v.begin(),v.end());
        mn=min(mn,v[2]-v[0]);
    }
    cout<<mn;
    return 0;
}
