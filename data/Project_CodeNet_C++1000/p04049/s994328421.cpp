#include<iostream>
#include<vector>
using namespace std;

vector<int> G[2005];
int f(int cent, int par, int len, int depth = 0){  
    int cut = 0;
    if (depth > len)
        ++cut;
    for(int i : G[cent]){
        if (i == par) 
            continue;
        cut += f(i, cent, len, depth + 1);
    }
    
    return cut;
}

int main(){
    int n, k, ans = 2005; cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    if (k % 2 == 0){
        for (int i = 1; i <= n; i++){
            ans = min(ans, f(i, -1, k/2));
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j : G[i]){
                ans = min(ans, f(i, j, k/2) + f(j, i, k/2));
            }
        }
    }
    cout << ans << endl;
}
