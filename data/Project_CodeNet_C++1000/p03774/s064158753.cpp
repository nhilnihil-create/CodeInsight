#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define log(x,b) (log(b)/log(x))
#define rep(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int mod=1e9;

int32_t main()
{
    int n,m;
    cin>>n>>m;
    int x[50],y[50],a[50],b[50],res[50]={0};
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++){
        int men=mod;
        for(int j=1;j<=m;j++){
            int dist=abs(x[i]-a[j])+abs(y[i]-b[j]);
            if(dist<men){
                men=dist;
                res[i]=j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<endl;
    }


    return 0;
}
