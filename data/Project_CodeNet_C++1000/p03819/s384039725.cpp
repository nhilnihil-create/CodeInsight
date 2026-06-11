#include <bits/stdc++.h>
const int N=400005;
using namespace std;
typedef pair<int,int> pii;
int n,m,dp[N],cur;
vector<pii>g[N];
void add(int pos,int val){
    while(pos<N){
        dp[pos]+=val;
        pos+=pos&(-pos);
    }
}
int get(int pos){
    int ans=0;
    while(pos){
        ans+=dp[pos];
        pos-=pos&(-pos);
    }
    return ans;
}
int main()
{ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>n>>m;
    cur=n;
    for(int i=1;i<=n;i++){
        int l,r;cin>>l>>r;
        g[r-l+1].push_back({l,r});
    }
    for(int i=1;i<=m;i++){
        int v=cur;
        for(int j=0;j<N;j+=i)v+=get(j);
        cout<<v<<'\n';
        for(auto el:g[i]){
            cur--;
            add(el.first,1);
            add(el.second+1,-1);
        }
    }
    return 0;
}
