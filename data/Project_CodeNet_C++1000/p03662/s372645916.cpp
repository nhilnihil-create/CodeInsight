#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iterator>
//#include<math.h>

using namespace std;
#define int long long
/*                      */    //#undef int
#define INF 1000000009
#define INFL 1000000000000000018ll
#define mod 1000000007ll
#define pb push_back
#define fi first
#define se second
#define mk make_pair
typedef pair<int, int> PA;
typedef priority_queue<int> PQ;
typedef priority_queue<PA, vector<PA>, greater<PA> >PQG;

int N, a[100005], b[100005], ds[100005], df[100005];
vector<int> G[100005];

void bfs(int s, int *d)
{
    queue<PA> que;
    bool used[100005] = {false};
    fill(d, d + N + 1, INFL);
    d[s] = 0;
    used[s] = true;
    que.push(mk(0, s));
    while(!que.empty()){
        int dis = que.front().first;
        int pos = que.front().second;
        que.pop();
        for(int i = 0; i < (int)G[pos].size(); i++){
            int to = G[pos][i];
            if(!used[to]){
                que.push(mk(dis + 1, to));
                d[to] = dis + 1;
                used[to] = true;
            }
        }
    }
}

int ansbfs(int s, int t)
{
    int res = 1;
    queue<int> que;
    bool used[100005] = {false};
    que.push(s);
    used[s] = true;
    used[t] = true;
    while(!que.empty()){
        int pos = que.front();
        que.pop();
        for(int i = 0; i < (int)G[pos].size(); i++){
            int to = G[pos][i];
            if(!used[to]){
                que.push(to);
                used[to] = true;
                res++;
            }
        }
    }
    return res;
}

signed main()
{
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        cin >> a[i] >> b[i];
        G[a[i]].pb(b[i]);
        G[b[i]].pb(a[i]);
    }
    //1からの最短路
    bfs(1, df);
    //Nからの最短路
    bfs(N, ds);
    int distf = df[N] / 2;
    int dists = df[N] - 1 - distf;
    int ansf = 0, anss = 0;
    for(int i = 0; i < N; i++){
        if(distf == df[a[i]] && dists == ds[b[i]]){
            //a[i]を根とするfの領地の数と、b[i]を根とするsの領地の数を求める
            ansf = ansbfs(a[i], b[i]);
            anss = ansbfs(b[i], a[i]);
        }
        else if(distf == df[b[i]] && dists == ds[a[i]]){
            ansf = ansbfs(b[i], a[i]);
            anss = ansbfs(a[i], b[i]);
        }
    }
    if(ansf <= anss){
        printf("Snuke\n");
    }
    else{
        printf("Fennec\n");
    }

    return 0;
}
/*


*/
