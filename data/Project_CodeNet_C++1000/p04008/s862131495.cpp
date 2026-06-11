#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<vector<int> > g(n);
    vector<int> a(n), d(n,1), deg(n);
    cin >> a[0];
    for(int i=1;i<n;i++){
        cin >> a[i];
        a[i]--;
        deg[a[i]]++;
    }
    queue<int> que;
    for(int i=1;i<n;i++){
        if(deg[i]==0) que.push(i);
    }
    while(!que.empty()){
        int v = que.front();
        que.pop();
        if(v == 0) continue;
        if(d[v]==k && a[v] != 0){
            ans++;
            d[v] = 0;
        }
        int p = a[v];
        d[p] = max(d[p], d[v]+1);
        deg[p]--;
        if(deg[p]==0) que.push(p);
    }
    if(a[0] != 1) ans++;
    cout << ans << endl;
    return 0;
}
