#include <bits/stdc++.h>
#include <climits>
using namespace std;


int N,M;
map<int,vector<int>> mp;

bool dfs(int a,int k){
    
    if(k == 1){
        for(auto u:mp[a]){
            if(u==N)return true;
        
        }
        return false;
        
    }
    
    for(auto u:mp[a]){
        if(dfs(u,k+1))return true;
    }
    return false;
}

int main(){
    

    cin >> N >> M;
    
    int a,b;
    for(int i = 0; i < M;i++){
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    
    if(dfs(1,0))cout <<"POSSIBLE"<<endl;
    else cout <<"IMPOSSIBLE"<<endl;
    
    
}