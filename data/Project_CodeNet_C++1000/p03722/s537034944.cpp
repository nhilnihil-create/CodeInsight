//code by lynmisakura.wish to be accepted!
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,M;
vector<pair<int,ll>> g[2010];
ll dist[2010];

int main(int argc, char const *argv[])
{
    scanf("%d %d",&N,&M);
    for (int i = 0; i < M; ++i)
    {
        int a,b;long long c;
        scanf("%d %d %lld",&a,&b,&c);
        a--,b--;
        g[a].emplace_back(b,-c);
        // g[b].emplace_back(a,-c);
    }

    bool negative = false;
    const long long INF = 1LL << 55;
    fill(dist,dist + N,INF);
    dist[0] = 0;

    for(int i = 0;i < 2*N;i++){
        for(int j = 0;j < N;j++){
            if(dist[j] >= INF/2)continue;
            else{
                for(auto &e : g[j]){
                    if(dist[e.first] > dist[j] + e.second){
                        if(i == N)dist[e.first] = -INF;
                        else dist[e.first] = dist[j] + e.second;
                    }
                }
            }
        }
    }
    if(dist[N-1] <= -INF/2){
        cout << "inf" << endl;
    }else{
        cout << -dist[N-1] << endl;
    }
//    cout << -dist[N-1] << endl;
    return 0;
}
