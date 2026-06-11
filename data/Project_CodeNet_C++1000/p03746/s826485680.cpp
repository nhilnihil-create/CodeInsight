#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i]+1;
    }
}

bool dfs(int node, vector<int> &path, vector<vector<int> > &edges, vector<int> &used){
    if(used[node]==1){
        return false;
    }
    used[node]=1;
    path.push_back(node);
    bool flag=true;

    for(auto v: edges[node]){
        if(dfs(v, path, edges, used)){
            return true;
        }
    }
    return true;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int> > edges(N,vector<int>(0));
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> ans(0);
    vector<int> used(N,0);
    if((int)edges[0].size()==1){
        dfs(0, ans, edges, used);
    }else{
        used[0]=1;
        dfs(edges[0][0], ans, edges, used);
        reverse(ans.begin(), ans.end());
        ans.push_back(0);

        for(int i=1; i<(int)edges[0].size(); i++){
            if(dfs(edges[0][i], ans, edges, used)){
               	break;
            }
        }
    }
  	cout << (int)ans.size() << endl;
  	cout_vec(ans);

}
