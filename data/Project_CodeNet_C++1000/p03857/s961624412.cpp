#include <bits/stdc++.h>
using namespace std;


vector<int> graph1[200010];
vector<int> graph2[200010];

pair<int, int> p[200010];
int visited[200010] = {};
int visited2[200010] = {};


void dfs1(int i, int num){
    if(visited[i] != 0){
        return;
    }

    visited[i] = num;
    p[i].first = num;

    for(int j = 0;j < graph1[i].size();j++){
        dfs1(graph1[i][j], num);
    }

    return;
}

void dfs2(int i, int num){
    if(visited2[i] != 0){
        return;
    }

    visited2[i] = num;
    p[i].second = num;

    for(int j = 0;j < graph2[i].size();j++){
        dfs2(graph2[i][j], num);
    }

    return;
}

int main(){
    int n;
    int k, l;
    cin >> n >> k >> l;

    map<pair<int, int>, int> mp;

    int s, t;
    for(int i = 0;i < k;i++){
        cin >> s >> t;
        s--; t--;
        graph1[s].push_back(t);
        graph1[t].push_back(s);
    }

    for(int i = 0;i < l;i++){
        cin >> s >> t;
        s--; t--;
        graph2[s].push_back(t);
        graph2[t].push_back(s);
    }

    int num = 1;
    for(int i = 0;i < n;i++){
        dfs1(i, num++);
        num++;
    }

    num = 1;
    for(int i = 0;i < n;i++){
        dfs2(i, num);
        num++;
    }

    for(int i = 0;i < n;i++){
        mp[p[i]]++;
    }

    for(int i = 0;i < n;i++){
        cout << mp[p[i]];
        if(i != n-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }

    return 0;
}