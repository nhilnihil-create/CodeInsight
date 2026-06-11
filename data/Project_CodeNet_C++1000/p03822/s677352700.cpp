#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

class Tree{
public:
    int N;
    vector<vector<int>> G;

    Tree(int _N){
        N = _N;
        G.resize(N);
    }

    void make_edge(int s, int t){
        G[s].push_back(t);
    }

    int dfs(int n, int par){
        vector<int> v;
        for(int i = 0; i < (int) G[n].size(); i++){
            int nx = G[n][i];
            if(nx != par){
                v.push_back(dfs(nx, n));
            }
        }

        int sz = v.size();
        int ret;
        if(sz == 0) ret = 0;
        else {
            sort(v.begin(), v.end(), greater<int>());
            for(int i = 0; i < sz; i++){
                v[i] += i;
            }
            ret = *max_element(v.begin(), v.end());
        }

        //cout << n << endl;
        //for(int i = 0; i < sz; i++) cout << v[i] << " ";
        //cout << endl << ret << endl << endl;

        return ret + 1;
    }
};

int main(){
    int N;
    cin >> N;

    Tree tr = Tree(N);
    for(int i = 0; i < N - 1; i++){
        int a;
        cin >> a;
        tr.make_edge(a - 1, i + 1);
    }

    cout << tr.dfs(0, -1) - 1 << endl;
    return 0;
}