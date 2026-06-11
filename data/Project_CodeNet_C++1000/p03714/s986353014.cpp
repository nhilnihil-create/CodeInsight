#include<bits/stdc++.h>
using namespace std;
int n;
long long arr[300010],sum,sum_1,sum1[300010],sum2[300010],sum3[300010],sum4[300010];
multiset<long long> s1,s2,s3,s4;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=3*n;i++)
    {
        cin>>arr[i];
        if(i<=n)
        {
            s1.insert(arr[i]);
            s2.insert(-arr[i]);
            sum+=arr[i];
            sum_1+=arr[i];
            sum1[i]=sum;
            sum2[i]=sum_1;
        }
    }
    multiset<long long>::iterator it1,it2;
    for(int i=n+1;i<=2*n;i++)
    {
        //cout<<i<<" "<<arr[i]<<" "<<*s1.begin()<<"\n";
        it1=s1.lower_bound(arr[i]);
        it2=s2.lower_bound(-arr[i]);
        if(it1!=s1.begin())
        {
            sum-=(*s1.begin());
            sum+=arr[i];
            s1.erase(s1.begin());
            s1.insert(arr[i]);
            //cout<<i<<" "<<sum1[i]<<"\n";
        }
            sum1[i]=sum;
        if(it2!=s2.begin())
        {
            sum_1+=(*s2.begin());
            sum_1+=arr[i];
            s2.erase(s2.begin());
            s2.insert(-arr[i]);
        }
            sum2[i]=sum_1;
    }
    sum=sum_1=0;
    for(int i=3*n;i>=2*n+1;i--)
    {
        if(i>=2*n+1)
        {
            s3.insert(arr[i]);
            s4.insert(-arr[i]);
            sum+=arr[i];
            sum_1+=arr[i];
            sum3[i]=sum;
            sum4[i]=sum_1;

        }
    }
    for(int i=2*n;i>=n+1;i--)
    {
        it1=s3.lower_bound(arr[i]);
        it2=s4.lower_bound(-arr[i]);
        //cout<<*it1<<" " <<*it2<<"\n";
        if(it1!=s3.begin())
        {
            sum-=(*s3.begin());
            sum+=arr[i];
            s3.erase(s3.begin());
            s3.insert(arr[i]);
        }
            sum3[i]=sum;
        if(it2!=s4.begin())
        {
            sum_1+=(*s4.begin());
            sum_1+=arr[i];
            s4.erase(s4.begin());
            s4.insert(-arr[i]);
        }
            sum4[i]=sum_1;
        //cout<<i<<" "<<sum4[i]<<"\n";
    }
    //cout<<"\n";
    long long mx=-1e18;
    for(int i=n;i<=2*n;i++)
    {
        //cout<<sum1[i]<<" "<<sum4[i+1]<<"\n";
        mx=max(mx,max(sum1[i]-sum4[i+1],sum2[i]-sum3[i+1]));
    }
    cout<<mx;
    return 0;
}
