#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

#define rep(i, n) for(long int i = 0; i < n; i++)
long int n, W;
pair<long int, long int> p[100];
vector<long int> a[4];

long int dfs(long int w0, long int w1, long int w2, long int w3){
    long int res = 0;
    long int weight = 0;
    weight += w0 * p[0].second;
    weight += w1 * (p[0].second + 1);
    weight += w2 * (p[0].second + 2);
    weight += w3 * (p[0].second + 3);
    if (weight > W){
        return res;
    }
    
    for (long int i = 0; i < w0; i++){
        res += a[0][i];
    }
    for (long int i = 0; i < w1; i++){
        res += a[1][i];
    }
    for (long int i = 0; i < w2; i++){
        res += a[2][i];
    }
    for (long int i = 0; i < w3; i++){
        res += a[3][i];
    }
    
    return res;
}

int main(){
    cin >> n >> W;
    rep(i, n) cin >> p[i].second >> p[i].first;
    rep(i, n) a[p[i].second - p[0].second].push_back(p[i].first);
    rep(i, 4){
        sort(a[i].begin(), a[i].end(), greater<long int>());
    }
    
    long int num[4];
    rep(i, 4) num[i] = a[i].size();
    long int ans = 0;
    rep(i, a[0].size()+1)rep(j, a[1].size()+1)rep(k, a[2].size()+1)rep(l, a[3].size()+1){
        ans = max(dfs(i, j, k, l), ans);
    }
    cout << ans << endl;
}
