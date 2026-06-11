#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N;
long long A[100000];
vector<pair<int, int> > adj[100000];
long long edge_label[100000];
bool visited[100000], visited2[100000];

long long make_edge_label(int now){
    // 子ノードへのedgeのlabelの和を返す
    visited[now] = true;
    long long ret = 0;
    for(int i = 0; i < adj[now].size(); i++){
        int next = adj[now][i].first;
        int edge_idx = adj[now][i].second;
        if(visited[next]){
            continue;
        }
        if(adj[next].size() == 1){
            edge_label[edge_idx] = A[next];
            ret += edge_label[edge_idx];
        }else{
            long long tmp = make_edge_label(next);
            edge_label[edge_idx] = 2*A[next] - tmp;
            if(edge_label[edge_idx] < 0){
                cout << "NO" << endl;
                exit(0);
            }
            ret += edge_label[edge_idx];
        }
    }
    return ret;
}

void check_consistency(int now){
    visited2[now] = true;
    for(int i = 0; i < adj[now].size(); i++){
        int next = adj[now][i].first;
        if(visited2[next] == false){
            visited2[next] = true;
            check_consistency(next);
        }
    }
    if(adj[now].size() == 1){
        return;
    }
    long long sum = 0, max_label = 0;
    for(int i = 0; i < adj[now].size(); i++){
        int edge_idx = adj[now][i].second;
        sum += edge_label[edge_idx];
        max_label = max(max_label, edge_label[edge_idx]);
    }
    if(sum % 2 != 0 || 2*max_label > sum){
        cout << "NO" << endl;
        exit(0);
    }
}


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(make_pair(b, i));
        adj[b].push_back(make_pair(a, i));
    }

    long long label_0 = make_edge_label(0);
    if(adj[0].size() == 1){
        if(label_0 != A[0]){
            cout << "NO" << endl;
            return 0;
        }
    }else{
        if(label_0 != 2 * A[0]){
            cout << "NO" << endl;
            return 0;
        }
    }

    check_consistency(0);
    /*
    for(int i = 0; i < N - 1; i++){
        cout << edge_label[i] << endl;
    }
    */
    cout << "YES" << endl;
    
        
}

