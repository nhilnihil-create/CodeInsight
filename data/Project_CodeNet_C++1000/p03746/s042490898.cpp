#include <bits/stdc++.h>
using namespace std;

vector<int> edge[100010];
vector<bool> visit(100010, false);

int main(){
    ios::sync_with_stdio(false);
    int a, b, n, m;  cin >> n >> m;
    for(int i=0;m>i;i++){
        cin >> a >> b;
        edge[a].push_back(b);   edge[b].push_back(a);
    }
    deque<int> ans; ans.push_back(a); ans.push_back(b);
    visit[a]=visit[b]=true; bool check=true;
    while(check){
        check=false;
        int p=ans.front();   int q=ans.back();
        for(int i=0;edge[p].size()>i;i++){
            if(!visit[edge[p][i]]){
                check=true; visit[edge[p][i]]=1;    ans.push_front(edge[p][i]); break;
            }
        }
        for(int i=0;edge[q].size()>i;i++){
            if(!visit[edge[q][i]]){
                check=true; visit[edge[q][i]]=1;    ans.push_back(edge[q][i]); break;
            }
        }
    }
    cout << ans.size() << "\n";
    for(int i=0;ans.size()>i;i++){
        cout << ans[i] << " ";
    }

}
























