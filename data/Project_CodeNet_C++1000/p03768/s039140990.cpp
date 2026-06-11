#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[100002], b[100002];
    vector<int> v[100002];
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    int q;
    cin >> q;
    int near[100002];
    int col[100002] {0};
    fill(near, near + n, -1);
    int w[100002], d[100002], c[100002];
    for(int i = q - 1; i >= 0; i--){
        cin >> w[i] >> d[i] >> c[i];
        w[i]--;
    }
    for(int i = 0; i < q; i++){
        queue<int> que;
        if(near[w[i]] == -1) col[w[i]] = c[i];
        near[w[i]] = d[i];
        que.push(w[i]);
        while(que.size()){
            int now = que.front();
            que.pop();
            if(near[now] == 0) continue;
            for(int next : v[now]){
                if(near[next] < near[now] - 1){
                    if(near[next] == -1) col[next] = c[i];
                    near[next] = near[now] - 1;
                    que.push(next);
                }
            }
        }
    }
    for(int i = 0; i < n; i++) cout << col[i] << endl;
}