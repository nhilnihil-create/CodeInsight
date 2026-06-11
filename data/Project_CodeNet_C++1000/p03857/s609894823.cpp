#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
const int MAX_N = 301100;
const int INF = 101100;

int N,K,L;

vector<int> RL[MAX_N];
vector<int> TL[MAX_N];
int r_visit[MAX_N];
int t_visit[MAX_N];
int ans;

void dfs_r(int v, int index){
    r_visit[v] = index;
    for(int i = 0; i < RL[v].size(); i++){
        int next = RL[v][i];
        if(r_visit[next] == INF){
            dfs_r(next, index);
        }
    }
}

void dfs_t(int v, int index){
    t_visit[v] = index;
    for(int i = 0; i < TL[v].size(); i++){
        int next = TL[v][i];
        if(t_visit[next] == INF){
            dfs_t(next, index);
        }
    }
}

void dfs(int v, bool road, bool train){
    if(train) t_visit[v] = train;
    if(road) r_visit[v] = road;
    if(r_visit[v] == t_visit[v] && t_visit[v] == true) ans++;

    if(train){
        for(int i = 0; i < TL[v].size(); i++){
            int next = TL[v][i];
            if(!t_visit[next]){
                dfs(next, false, train);
            }
        }
    }

    if(road){
        for(int i = 0; i < RL[v].size(); i++){
            int next = RL[v][i];
            if(!r_visit[next]){
                dfs(next, road, false);
            }
        }
    }
}

map<pair<int, int>, int> s;
int main(){
    cin >> N >> K >> L;
    REP(i,K){
        int p,q;
        cin >> p >> q;
        p--; q--;
        RL[p].push_back(q);
        RL[q].push_back(p);
    }
    REP(i,L){
        int r,s;
        cin >> r >> s;
        r--; s--;
        TL[r].push_back(s);
        TL[s].push_back(r);
    }

    int rindex = 0;
    int tindex = 0;
    fill(r_visit, r_visit+N, INF);
    fill(t_visit, t_visit+N, INF);
    for(int i = 0; i < N; i++){
        if(r_visit[i] == INF) dfs_r(i, rindex++);
        if(t_visit[i] == INF) dfs_t(i, tindex++);
    }
    for(int i = 0; i < N; i++){
        s[make_pair(r_visit[i], t_visit[i])]++;
    }
    for(int i = 0; i < N; i++){
        int ans = s[make_pair(r_visit[i], t_visit[i])];
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}
