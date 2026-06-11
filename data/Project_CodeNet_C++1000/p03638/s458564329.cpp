#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<long long,int> P;

int main(){
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    priority_queue<int> que;
    
    rep(i, n){
        rep(j, a[i]) que.push(i+1);
    }

    vector<vector<int>> ans;

    rep(y, h){
        vector<int> tmp;
        rep(x, w){
            int p = que.top();
            que.pop();
            tmp.push_back(p);
        }
        if(y%2 == 1) reverse(tmp.begin(), tmp.end());
        ans.push_back(tmp);
    }

    rep(y, h){
        rep(x, w) cout << ans[y][x] << " ";
        cout << endl;
    }

    return 0;
}