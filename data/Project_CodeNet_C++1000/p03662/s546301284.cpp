#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<vector<int>> tr;
vector<int> root;
bool rooted = false;
bool visited[100005];

void path(int s, int t){
    if(!rooted){root.push_back(s);}
    visited[s] = true;
    for (auto v1: tr[s]) {
        if(v1==t){
            rooted = true;
            root.push_back(t);
        }
        if(visited[v1] == false && v1 != t){
            path(v1,t);
        }
    }
    if(!rooted){root.pop_back();}
}

void dfs(int s, int t, int* cnt){
    (*cnt)++;
    visited[s] = true;
    for (auto v1: tr[s]) {
        if(visited[v1] == false && v1 != t){
            dfs(v1,t,cnt);
        }
    }
}


int main(){
    int n;
    cin >> n;
    tr.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    path(0,n-1);
    int cuta,cutb;
    if(root.size()&1){
        cuta = root[root.size()/2];
        cutb = root[root.size()/2+1];
    }else{
        cuta = root[root.size()/2-1];
        cutb = root[root.size()/2];
    }
    int fennec = 0, snuke = 0;
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    dfs(0, cutb, &fennec);
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    dfs(n-1, cuta, &snuke);
    if(fennec>snuke){cout << "Fennec" << endl;}
    else{cout << "Snuke" << endl;}



    return 0;

}
