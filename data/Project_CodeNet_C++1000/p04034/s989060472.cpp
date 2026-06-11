#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    bool flag = false;
    vector<int> visited(n);
    visited[0] = 1;
    vector<int> ball(n,1);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        x -= 1;
        y -= 1;

        ball[x] -= 1;
        ball[y] += 1;
        if((flag == false && x == 0) || visited[x] == 1){
            visited[y] = 1;
            flag = true;
        }
        if(ball[x] == 0) visited[x] = 0;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans += visited[i];
    }
    cout << ans << endl;

    return 0;
}