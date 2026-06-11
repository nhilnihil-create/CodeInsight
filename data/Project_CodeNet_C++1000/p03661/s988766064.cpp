#define MOD 1000000007;
#define input ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll long long

#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
set<int> st[N+1];
int main() {

    int n;
    cin>>n;
    vector<int> vec;
    ll sum=0;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        vec.push_back(x);
        sum+=x;
    }
    sum-=vec[0];
    ll sum2=vec[0];
    ans=abs(sum2-sum);
    for(int i=1;i<n-1;i++)
    {
        sum2+=vec[i];
        sum-=vec[i];
        ans=min(abs(sum2-sum),ans);
    }
    cout<<ans;

}