#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000000
#define MAX 200001
#define MOD 1000000007  

int dfs(int s, Graph &G){
    vector<int> ans;
    for(auto v:G[s]){
        int n = dfs(v, G);
        ans.push_back(n + 1);
    }
    sort(ans.begin(), ans.end());
    int ANS = 0;
    if(ans.size() != 0){
        ANS = ans[0];
        for(int i = 1; i < ans.size(); i++){
            if(ANS >= ans[i]) ANS++;
            else
             ANS = ans[i];
        }
    }
    return ANS;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int a;
        cin >> a;
        a--;
        G[a].push_back(i + 1);
    }
    int ans = dfs(0, G);
    cout << ans << endl;
}
