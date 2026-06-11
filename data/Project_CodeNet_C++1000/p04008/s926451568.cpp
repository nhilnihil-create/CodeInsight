#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
priority_queue<i_i> leaves;
vector<int> children[102000];
int ans = 0;
int parent[102000];

void dfs(int now, int depth){
    if(children[now].size() == 0){
        i_i in = {depth, now};
        leaves.push(in);
        return;
    }
    for(int i = 0; i < children[now].size(); i++){
        dfs(children[now][i], depth + 1);
    }
    return;
}

int main() {
    //cout.precision(10);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> parent[i];
    }
    if(parent[1] != 1){
        parent[1] = 1;
        ans++;
    }
    if(k >= (n - 1)){
        cout << ans << endl;
        return 0;
    }
    for(int i = 2; i <= n; i++){
        children[parent[i]].push_back(i);
    }
    dfs(1, 0);
    while(!leaves.empty()){
        i_i out = leaves.top();
        leaves.pop();
        //cout << out.first << endl;
        if(out.first <= k){
            break;
        }
        int now = out.second;
        for(int i = 1; i < k; i++){
            int next = parent[now];
            parent[now] = 1;
            now = next;
            //now = parent[now];
            if(now == 1){
                break;
            }
        }
        if(parent[now] == 1){
            continue;
        }
        ans++;
        i_i in = {out.first - k, parent[now]};
        parent[now] = 1;
        if(in.first <= k){
            continue;
        }
        leaves.push(in);
    }
    cout << ans << endl;
    return 0;
}

