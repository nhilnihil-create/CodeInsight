#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 100001;

int n, k;
vector <int> a, v[N];
int ans;

int dfs(int node){
    int ret = 0;
    for(auto &i : v[node]){
        ret = max(ret, dfs(i));
    }
    if(a[node] && ret == k - 1){
        ans++;
        return 0;
    }
    return ret + 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    a.resize(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        a[i]--;
        if(i > 0) v[a[i]].push_back(i);
    }
    ans = a[0] > 0;
    a[0] = 0;
    dfs(0);
    cout << ans << endl;
}
