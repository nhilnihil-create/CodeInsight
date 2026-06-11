#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(long long i = 0; i < (n); i++)
using namespace std;
int main()
{
    const long long INF = 100000000;
    long long N, M, R, ans = INF;
    cin>>N>>M>>R;
    vector<long long>r(R);
    rep(i,R){
        cin>>r[i];
        --r[i];
    }
    vector<vector<long long>>adj(N,vector<long long>(N, INF));
    rep(i,N) adj[i][i] = 0;
    
    rep(i,M){
        long long A, B, C;
        cin>>A>>B>>C;
        --A;
        --B;
        adj[A][B] = adj[B][A] = C;
    }

    rep(k,N){
        rep(i,N){
            rep(j,N){
                if(adj[i][k] != INF && adj[k][j] != INF){
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    sort(r.begin(), r.end());
    do{
        long long a = 0;
        rep(i,R-1){
            if(adj[r[i]][r[i+1]] != INF) a += adj[r[i]][r[i+1]];
        }
        ans = min(ans,a);
    }while(next_permutation(r.begin(), r.end()));

    cout<<ans<<endl;
    return 0;
}