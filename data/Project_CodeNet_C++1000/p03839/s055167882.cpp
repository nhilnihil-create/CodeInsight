# include <iostream>
using namespace std;

long long N;
long long K;
long long a[100005];
long long prefixsum[100005];
long long pprefixsum[100005];
long long tempsum;
long long ans=0;
long long totalsum;

long long psum(long long left, long long right) //sum from left to right indexes//
{
    return prefixsum[right]-prefixsum[left-1];
}

long long ppsum(long long left, long long right)
{
    return pprefixsum[right]-pprefixsum[left-1];
}

int main()
{
    cin>>N>>K;

    for (long long i=1; i<=N; i++)
    {
        cin>>a[i];
        totalsum=totalsum+a[i];
    }

    for (long long i=1; i<=N; i++)
    {
        prefixsum[i]=prefixsum[i-1]+a[i];
    }

    for (long long i=1; i<=N; i++)
    {
        pprefixsum[i]=pprefixsum[i-1];
        if (a[i]>0)
        {
            pprefixsum[i]=pprefixsum[i]+a[i];
        }
    }

    for (long long i=1; i<=N-K+1; i++)
    {
        tempsum=psum(i, i+K-1);

        if (tempsum>=0)
        {
            tempsum=tempsum+ppsum(1, i-1)+ppsum(i+K, N);
            ans=max(ans, tempsum);
        }

        else
        {
            ans=max(ans, ppsum(1, i-1)+ppsum(i+K, N));
        }
    }

    cout<<ans;
}