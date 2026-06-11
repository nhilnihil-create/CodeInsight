#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
    const long long INF = 1e9;
    long long n,m,r;
    cin>>n>>m>>r;
    vector<long long> t(r);
    for(long long i=0;i<r;++i){
        cin>>t[i];
        t[i]--;
    }
    vector<vector<long long>> adj(n,vector<long long>(n,INF));
    for(long long i=0;i<n;++i){
        adj[i][i]=0;
    }
    for(long long i=0;i<m;++i){
        long long a,b,c;
        cin>>a>>b>>c;
        --a; --b;
        adj[a][b]=adj[b][a]=c;
    }

    //フロイド法
    for(long long k=0;k<n;++k){
        for(long long i=0;i<n;++i){
            for(long long j=0;j<n;++j){
                if(adj[i][k]!=INF && adj[k][j]!=INF){
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
    }

    //tをsortしてnext_permutaionでうまくやる
    sort(t.begin(),t.end());
    long long ans=INF;
    do{
        long long tmp=0;
        for(long long i=0;i<r-1;++i){
            tmp+=adj[ t[i] ][ t[i+1] ];
        }
        if(ans>tmp) ans=tmp;
    }while(next_permutation(t.begin(),t.end()));

    cout<<ans<<endl;
    return 0;
}