#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

vector<vector<int>> child;

int dfs(int node){
    vector<int> v;

    for(int i=0;i<child[node].size();i++){
        v.push_back(dfs(child[node][i]));
    }
    sort(ALL(v));
    int tmp = 0;
    for(int i=0;i<v.size();i++){
        tmp = max(tmp,(int)( (v.size() - i) + v[i]));
    }
    return tmp;
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
    cin >> N;
    child.resize(N);
    rep(i,N-1){
        int a;
        cin >> a;
        a--;
        child[a].push_back(i+1);
    }
    cout << dfs(0) << endl;
}