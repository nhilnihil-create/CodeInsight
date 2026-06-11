#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
vector<vector<int>> v(111111);
vector<int> ans;
bool used[111111];

bool dfs(int p){
    used[p]=true;
    if(p!=0) ans.push_back(p);
    bool end = 1;
    bool ret = 0;
    
    for(auto i:v[p]){
        if(!used[i]){
            end = false;
            ret |= dfs(i);
        }
        if(ret) break;
    }

    return true;
    
}

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ans.push_back(0);
    dfs(0);
    reverse(ans.begin(),ans.end());
    dfs(0);
    cout << ans.size() << endl;
    for(auto i:ans){
        cout<<i+1<<" ";
    }
    cout<<endl;


    
    
}