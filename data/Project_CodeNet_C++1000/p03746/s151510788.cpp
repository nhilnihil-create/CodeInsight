#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
int N, M;
int used[MAX_N+5];
vector<vector<int>> E(MAX_N+5);
deque<int> ans;

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<M;i++){
        int a, b; scanf("%d %d", &a, &b);
        E[a].push_back(b); E[b].push_back(a);
    }

    ans.push_back(1); used[1]++;
    while(1){
        bool ok = true;
        int v = ans.front();
        for(int i=0;i<E[v].size();i++){
            if(!used[E[v][i]]){
                ans.push_front(E[v][i]); used[E[v][i]]++;
                ok = false; break;
            }
        }

        if(ok) break;
    }

    while(1){
        bool ok = true;
        int v = ans.back();
        for(int i=0;i<E[v].size();i++){
            if(!used[E[v][i]]){
                ans.push_back(E[v][i]); used[E[v][i]]++;
                ok = false; break;
            }
        }

        if(ok) break;
    }

    printf("%d\n", ans.size());
    for(int it : ans) printf("%d ", it);
    printf("\n");
    return 0;
}
