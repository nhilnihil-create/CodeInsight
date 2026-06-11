#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
vector<int> cld[N];

int dfs(int u) {

    vector<int> dep;
    for (int v: cld[u])     dep.push_back(dfs(v));
    sort(dep.rbegin(), dep.rend());

    int ans = 0;
    for (int i=0; i<dep.size(); i++)    ans = max(ans, dep[i]+i+1);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for (int i=2; i<=n; i++) {
        int p;
        cin>>p;
        cld[p].push_back(i);
    }

    cout<<dfs(1)<<endl;
}
