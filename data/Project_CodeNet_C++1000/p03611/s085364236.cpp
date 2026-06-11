#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define all(x) (x).rbegin(), (x).rend()
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    map<int,int>val;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        val[x]++;
        val[x-1]++;
        val[x+1]++;
    }
    int ans=0;
    for(auto t=val.begin();t!=val.end();t++){
        ans=max(ans,t->second);
    }
    cout<<ans<<endl;
}
