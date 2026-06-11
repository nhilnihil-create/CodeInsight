#include <iostream>
#include <vector>

using namespace std;

vector<int> G[100000];
long A[100000];
bool used[100000];
bool judge = true;

long dfs(int v){
    used[v] = true;
    if(G[v].size() == 1){
        //cout << v << ' ' << A[v] << endl;
        return A[v];
    }
    long sum = 0;
    for(int i = 0; i < G[v].size(); i++){
        long tmp;
        if(!used[G[v][i]]) {
            tmp = dfs(G[v][i]);
            if(tmp > A[v]) judge = false;
            sum += tmp;
        }
    }
    long ret = 2*A[v]-sum;
    if(ret < 0) judge = false;
    if(ret > A[v]) judge = false;
    //cout << v << ' ' << ret << endl;
    return ret;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        used[i] = false;
    }
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(N == 2){
        if(A[0] == A[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < N; i++){
        if(G[i].size() != 1){
            if(dfs(i) != 0 || !judge){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
            return 0;
        }
    }
}