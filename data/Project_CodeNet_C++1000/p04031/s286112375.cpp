#include<bits/stdc++.h>

#define ll   long long int
#define PI 3.14159265358979
#define zig ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;


int main()
{
    zig
    ll n, i, minm=1010000000000000, sum;
    cin>>n;
    vector<ll> vec(n);
    for(auto &i: vec)
        cin>>i;
    sort(vec.begin(), vec.end());
    for(i=vec[0]; i<=vec[n-1]; i++)
    {
        sum=0;
        for(auto j:vec)
        {
            sum+=((i-j)*(i-j));
        }
        minm=min(sum, minm);
    }
    cout<<minm<<'\n';
    return 0;
}
