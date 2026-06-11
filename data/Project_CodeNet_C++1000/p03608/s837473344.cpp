#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    const long long INF = 100000000;
    long long N, M, R;
    cin >> N >> M >> R;
    vector<long long>r(R);
    for(long long i = 0; i < R; ++i){
        cin >> r[i];
        --r[i];
    }
    vector<vector<long long>>adj(N, vector<long long>(N, INF));
    for(long long i = 0; i < N; ++i){
        adj[i][i] = 0;
    }
    for(long long i = 0; i < M; ++i){
        long long A, B, C;
        cin >> A >> B >> C;
        --A;
        --B;
        adj[A][B] = adj[B][A] = C;
    }
    for(long long k = 0; k < N; ++k){
        for(long long i = 0; i < N; ++i){
            for(long long j = 0; j < N; ++j){
                if(adj[i][k] != INF && adj[k][j] != INF){
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
    }
    long long ans = 100000000;
    sort(r.begin(), r.end());
    do{
        long long tmp = 0;
        for(int i = 1; i < R; ++i){
            tmp += adj[r[i-1]][r[i]];
        }
        ans = min(ans, tmp);
    }while(next_permutation(r.begin(), r.end()));
    cout << ans << endl;
}
