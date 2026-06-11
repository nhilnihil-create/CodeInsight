#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define all(x) x.begin(), x.end()
bool isPowerOfTwo(int n)
{
    return (ceil(log2(n)) == floor(log2(n)));
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,int>val;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        val[x]++;
    }
    int ans=0;
    for(auto it=val.begin();it!=val.end();it++)
    {
        if(it->second%2!=0)ans++;
    }
    cout<<ans<<endl;

    return 0;
}
