#include <bits/stdc++.h>
using namespace std;
int n,p1,p2,dep[100005],sz[100005],fa[100005];
vector<int> arr[100005];
void dfs(int cur,int pre,int d) {
    dep[cur]=d; sz[cur]=1; fa[cur]=pre;
    for (int i=0; i<arr[cur].size(); i++) {
        if (arr[cur][i]==pre) continue;
        dfs(arr[cur][i],cur,d+1);
        sz[cur]+=sz[arr[cur][i]];
    }
}
int main() {
    cin>>n;
    for (int i=0; i<n-1; i++) {
        cin>>p1>>p2; p1--; p2--;
        arr[p1].push_back(p2);
        arr[p2].push_back(p1);
    }
    dfs(0,-1,0);
    int up=(dep[n-1]-dep[0]-1)/2,cur=n-1;
    while (up!=0) {
        up--; cur=fa[cur];
    }
    if (n-sz[cur]>sz[cur]) cout<<"Fennec\n";
    else cout<<"Snuke\n";
}