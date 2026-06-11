#include <bits/stdc++.h> 
using namespace std; 
#define int long long
# define pii pair<int,int>
const int maxn=1e6+5;
signed main() { 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<string> a(n),b(m);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    bool exist=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i+m-1>=n || j+m-1>=n)continue;
            bool flag=true;
            for(int k=0;k<m;k++)
            {
                for(int l=0;l<m;l++)
                {
                    if(a[i+k][j+l]!=b[k][l])
                    {
                        flag=false;
                    }
                }
            }
            if(flag)
            {
                exist=true;
            }
        }
    }
    if(exist)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}