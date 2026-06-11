#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long 
#define F(n) for(int i = 0; i < n; ++i)
#define Debug cout<<endl<<"I AM IRONMAN"<<endl

int main ()
{
    fastio;
    vector<ll> v;
    ll sum=0;
    int n;
    cin >> n;
    for(int i=0;i<n*3;i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(),v.end(),greater<int>());
    int j=1;
    for(auto i: v)
    {
        if(j%2==0)
        {
            sum+=i;
        }
        if(j==(n*2))
        {
            break;
        }
        j++;
    }
    cout << sum;
    return 0;
}