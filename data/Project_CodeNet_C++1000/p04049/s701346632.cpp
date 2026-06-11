#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[2002], b[2002];
    vector<int> v[2002];
    for(int i = 0; i < n - 1; i++){
        cin >> a[i] >> b[i];
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    queue<int> que;
    int d[2003];
    int ans = 0;
    if(k % 2 == 0) for(int i = 1; i <= n; i++){
        fill(d, d + n + 1, -1);
        int count = 0;
        que.push(i);
        d[i] = 0;
        while(que.size()){
            int now = que.front();
            que.pop();
            if(d[now] <= k / 2 - 1){
                for(int next : v[now]){
                    if(d[next] == -1){
                        d[next] = d[now] + 1;
                        que.push(next);
                    }
                }
            }
            count++;
        }
        ans = max(ans, count);
    }
    if(k % 2 == 1) for(int i = 0; i < n - 1; i++){
        fill(d, d + n + 1, -1);
        int count = 0;
        que.push(a[i]);
        que.push(b[i]);
        d[a[i]] = 0;
        d[b[i]] = 0;
        while(que.size()){
            int now = que.front();
            que.pop();
            if(d[now] <= k / 2 - 1){
                for(int next : v[now]){
                    if(d[next] == -1){
                        d[next] = d[now] + 1;
                        que.push(next);
                    }
                }
            }
            count++;
        }
        ans = max(ans, count);
    }
    cout << n - ans << endl;
}