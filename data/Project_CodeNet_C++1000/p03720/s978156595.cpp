#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n, vector<int> (n, 0));
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edge[a - 1][b - 1] += 1;
        edge[b - 1][a - 1] += 1;
    }
    for(int i = 0; i < n; i++){
        int ans = 0;
        for(int x : edge[i]){
            ans += x;
        }
        cout << ans << endl;
    }
}