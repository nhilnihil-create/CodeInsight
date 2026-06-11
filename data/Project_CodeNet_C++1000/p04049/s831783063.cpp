#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
bool used[2020];
vector<vector<int>> v(2020);

int dfs(int p,int dist){
    used[p]=true;
    int ret=0;
    if(dist>k/2) ret++;
    for(auto i:v[p]){
        if(!used[i]){
            ret += dfs(i,dist+1);
        }
    }
    return ret;
}


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    cin>>n>>k;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[b].push_back(a);
        v[a].push_back(b);
    }
    int ans=1e9;
    if(k%2==0) {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) used[j]=false;
            ans = min(ans,dfs(i,0));
        }
    }
    else {
        k--;
        for(int i=0;i<n;i++){
            for(auto j:v[i]){
                for(int j=0;j<n;j++) used[j]=false;
                used[j]=true;
                int cnt=dfs(i,0);
                used[j]=false;
                cnt+=dfs(j,0);
                ans=min(ans,cnt);
            }
        }
    }
    cout<<ans<<endl;
    
    
}