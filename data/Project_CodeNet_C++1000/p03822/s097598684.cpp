#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    int N;
    cin >> N;
    int a[N+1];
    vector<int> edge[N+1];
    rep2(i, 2, N+1){
        cin >> a[i];
        edge[a[i]].push_back(i);
    }
    queue<int> que;
    int dep[N+1];
  	int cnt[N+1];
  	fill_n(cnt, N+1, 0);
    rep2(i, 1, N+1){
        if(edge[i].size() == 0){
            dep[i] = 0;
            que.push(i);
        }
    }
    while(!que.empty()){
        int i = que.front();
        que.pop();
        if(i == 1) break;
        int j = a[i];
        int n = edge[j].size();
      	cnt[j]++;
        if(cnt[j] < n) continue;
        int d[n];
        rep(k, n) d[k] = dep[edge[j][k]];
        sort(d, d+n, greater<int>());
        dep[j] = 0;
        rep(k, n){
            dep[j] = max(dep[j], d[k]+k+1);
        }
        que.push(j);
    }
    cout << dep[1] << endl;
}