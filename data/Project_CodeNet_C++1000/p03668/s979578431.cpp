#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2000000000;//10^9
ll MOD  = 998244353;
vector<vector<int>> edge(100010, vector<int>(0));
vector<int> parent(100010, -1);
vector<bool> vis(100010, 0);
vector<int> child[100010];

void makeParent(int N){
    vis.at(N) = 1;
    for(int i = 0; i < edge.at(N).size(); i++){
        if(vis.at(edge.at(N).at(i)) == 0){
            parent.at(edge.at(N).at(i)) = N;
            makeParent(edge.at(N).at(i));
            child[N].push_back(edge.at(N).at(i));
        }
    }
}
vector<int> memo(100010, -1);

int grundy(int x){
    if(memo.at(x) != -1) return memo.at(x);
    if(child[x].size() == 0)return 0;
    int XOR = grundy(child[x][0]) + 1;
    for(int i = 1; i < child[x].size(); i++){
        XOR ^= grundy(child[x][i]) + 1;
    }
    return memo.at(x) = XOR;
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        edge.at(x).push_back(y);
        edge.at(y).push_back(x);
    }
    
    makeParent(0);
    
    if(grundy(0)){
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
    }
    
    
}