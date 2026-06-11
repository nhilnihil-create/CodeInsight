#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    vector<long long> p(3*n);
    for(long long i=0;i<3*n;i++){
        long long a;
        cin>>a;
        p[i]=a;
    }
    sort(p.rbegin(), p.rend());
    long long sum=0;
    for(long long j=1;j<(3*n)-n;j+=2){
        sum+=p[j];
    }
    cout<<sum;
}