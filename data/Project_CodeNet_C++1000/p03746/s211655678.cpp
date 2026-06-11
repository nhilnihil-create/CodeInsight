#include<bits/stdc++.h>
using namespace std;

int main(){


    int n, m; cin >> n >> m;
    vector<vector<int> > g(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int L1 = 0;
    int L2 = g[0][0];
    list<int> ans;
    ans.push_back(L1);
    ans.push_back(L2);
    vector<bool> used(n, false);
    used[L1] = used[L2] = true;

    while(1){

        // L1 と L2 のうち
        bool flag = true;
        for(auto x : g[L1]){
            if(!used[x]){
                flag = false;
                used[x] = true;
                ans.push_front(x);
                L1 = x;
                break;
            }
        }

        if(!flag) continue;

        for(auto x : g[L2]){
            if(!used[x]){
                flag = false;
                used[x] = true;
                ans.push_back(x);
                L2 = x;
                break;
            }
        }

        if(flag){
            break;
        }
    }

    cout << ans.size() << endl;
    for(auto x : ans) cout << x + 1 << " ";
    cout << endl;


    return 0;
}