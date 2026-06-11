#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;


int N;
vector<char> op;
vector<ll> A;
char ops[2] = {'+', '-'};

ll memo[100000][3];


ll dfs(int p, int c){
    // clip c
    c = min(2, c);
    if(p == N) return 0;
    if(memo[p][c] != -1) return memo[p][c];
    ll ret = 0;
    if(c % 2 == 0){
        if(op[p] == '+'){
            ret = max(ret, A[p] + dfs(p+1, c));
        }else{
            ret = max(ret, -A[p] + dfs(p+1, c+1));
            if(c >= 1) ret = max(ret, A[p] + dfs(p+1, c));
        }
    }else{
        if(op[p] == '+'){
            ret = max(ret, -A[p] + dfs(p+1, c));
            ret = max(ret, A[p] + dfs(p+1, c-1));
        }else{
            ret = max(ret, A[p] + dfs(p+1, c+1));
        }
    }
    memo[p][c] = ret;
    return ret;
}


int main(){
    cin >> N;

    ll start;
    cin >> start;

    N--;
    op.resize(N);
    A.resize(N);
    for(int i=0;i<N;i++){
        cin >> op[i] >> A[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << start + dfs(0, 0) << endl;
    return 0;
}