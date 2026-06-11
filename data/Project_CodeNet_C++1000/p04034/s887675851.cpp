#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n+1, 1);
    vector<bool> red(n+1, false);
    red[1] = true;
    set<int> s;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        cnt[x]--, cnt[y]++;
        if(red[x]){
            red[y] = true;
            if(cnt[x] == 0) red[x] = false;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(red[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}