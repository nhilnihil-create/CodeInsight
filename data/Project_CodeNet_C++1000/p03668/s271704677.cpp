#include<bits/stdc++.h>
using namespace std;

vector<int> G[100001];
bool visited[100001];

int dfs(int v){
    int g=0;
    for(int i=0; i<G[v].size(); i++){
        if(visited[G[v][i]]==0){
            visited[G[v][i]]=1;
            g^=(dfs(G[v][i])+1);
        }
    }
    return g;
}

int main(){
    //input
    int N;
    cin >> N;
    int x,y;
    N--;
    while(N--){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    //calc
    for(int i=0; i<=100000; i++){
        visited[i]=0;
    }
    visited[1]=1;
    int grundy=dfs(1);
    

    //output
    if(grundy!=0){
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
    }
    system("pause");
    return 0;
}