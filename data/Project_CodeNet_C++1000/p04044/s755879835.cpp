

#include<bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL);

int main()
{
    speed;

    int n,l;
    cin>>n>>l;

    vector<string>v(n);
    string s,ans;

    for(int i=0;i<n;i++) cin>>v[i];

    sort(v.begin(),v.end());

    for(int i=0;i<n;i++) ans+=v[i];

    cout<<ans<<"\n";
}