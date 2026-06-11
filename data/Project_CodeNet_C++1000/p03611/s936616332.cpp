#include<bits/stdc++.h>
using namespace std;
#define Q int tc; scanf("%d",&tc);cin.ignore(); for(int q=1;q<=tc;q++)
typedef long long int ll;
#define MAX 100000

int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int xx;
        cin>>xx;
        v.push_back(xx);
    }
    sort(v.begin(),v.end());

    int mx=0,ans=0,cnt=0;
    for(int i=0;i<n;i++){
        int l=lower_bound(v.begin(),v.end(),v[i]-1)-v.begin();
        int u=upper_bound(v.begin(),v.end(),v[i]+1)-v.begin()-1;
        ans=max(ans,(u-l));
    }
    cout<<ans+1;
}

