#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front

int N, M;
bool used[100100];
deque<int> deq;
vector<int> G[100100];

void dfs(int v, bool f)
{
    used[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        int to = G[v][i];
        if(!used[to]){
            if(f){
                deq.pb(to);
            }
            else {
                deq.pf(to);
            }
            dfs(to, f);
            break;
        }
    }
    return;
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    deq.pb(0);
    dfs(0, true);
    dfs(0, false);
    printf("%d\n", deq.size());
    while(deq.size()){
        printf("%d", deq.front() + 1);
        if(deq.size() > 1){
            printf(" ");
        }
        deq.pop_front();
    }
    printf("\n");

    return 0;
}
