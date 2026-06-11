#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

vector<int> temp_node[100000];
int root = 0;

struct node{
    int parent;
    vector<int> child;
};

void construct_tree(node* nd, int s){
    rep(i, temp_node[s].size()){
        int to = temp_node[s][i];
        if(to == nd[s].parent) continue;
        nd[to].parent = s;
        nd[s].child.push_back(to);
        construct_tree(nd, to);
    }
}

int solve(node* nd, int s){
    if(nd[s].child.empty()) return 0;
    vector<int> res;
    rep(i, nd[s].child.size()){
        int to = nd[s].child[i];
        res.push_back(solve(nd, to));
    }
    sort(res.begin(), res.end());
    int val = res[0], row = 0;
    rep(i, res.size()){
        if(i == 0){
            row++;
        }
        else if(res[i] == res[i-1]){
            row++;
        }
        else{
            val += row;
            if(val < res[i]) val = res[i];
            row = 1;
        }
    }
    val += row;
    return val;
}

int main(void){
    int N; cin >> N;
    rep(i, N-1){
        int a; cin >> a;
        a--;
        temp_node[i+1].push_back(a);
        temp_node[a].push_back(i+1);
    }
    node nd[N];
    nd[root].parent = -1;
    construct_tree(nd, root);
    //cout << "constructed" << endl;

    cout << solve(nd, root) << endl;
    return 0;
}