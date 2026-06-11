#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m,s,g;
    cin >> n >> m;
    vector<int> G[100001],route(2);
    set<int> st[100001];
    vector<bool> visited(n+1,false);
    for(int i = 0;i < m;i ++){
        int a,b;
        cin >> a >> b;

        G[a].push_back(b),G[b].push_back(a);
        st[a].insert(b),st[b].insert(a);

        if(!i) {
            s=a,g=b;
            visited[s]=1,visited[g]=1;
            route[0]=s,route[1]=g;
            st[s].erase(g);
            st[g].erase(s);
        }    
    }
    while(st[s].size()||st[g].size()){
        if(st[s].size()){
            int s1 = *st[s].begin();
            while(st[s].size()&&visited[s1]) {
                st[s].erase(s1);
                if(st[s].size()) s1 = *st[s].begin();
            }
            if(!st[s].size()) continue;
            st[s].erase(s1),st[s1].erase(s);
            s = s1;
            visited[s]=1;
            route.insert(route.begin(),s);
        }
        if(st[g].size()){
            int g1 = *st[g].begin();
            while(st[g].size()&&visited[g1]) {
                st[g].erase(g1);
                if(st[g].size()) g1 = *st[g].begin();
            }
            if(!st[g].size()) continue;
            st[g].erase(g1),st[g].erase(g);
            g = g1;
            visited[g]=1;
            route.push_back(g);
        }
    }
    cout << route.size() << endl;
    for(int i = 0;i < route.size();i ++){
        cout << route[i] << " ";
    }
    cout << endl;
    return 0;
}