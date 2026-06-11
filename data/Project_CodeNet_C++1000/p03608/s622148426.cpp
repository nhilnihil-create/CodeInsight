#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    int n,m,R;
    cin>>n>>m>>R;
    vector<int> v;
    for(int i=0;i<R;i++){
        int r;
        cin>>r;
        v.push_back(r);
    }
    ll d[201][201]={};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) d[i][j]=1e18;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        d[a][b]=d[b][a]=c;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    ll ans=1e18;
    sort(v.begin(),v.end());
    do{
        ll Kyori=0;
        for(int i=1;i<R;i++){
            Kyori+=d[v[i-1]][v[i]];
        }
        ans=min(ans,Kyori);
    }while(next_permutation(v.begin(), v.end()));
    cout<<ans<<endl;
}