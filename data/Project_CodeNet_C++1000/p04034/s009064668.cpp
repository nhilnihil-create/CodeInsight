#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<bool> red(N);
    int cnt[N];
    for (int i = 0; i < N; i++)
    {
        red[i] = false;
        cnt[i] = 1;
    }
    red[0] = true;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(red[x] == true){
            red[y] = true;
        }
        cnt[x]--;
        cnt[y]++;
        if(cnt[x] == 0){
            red[x] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if(red[i] == true) ans++;
    }

    cout << ans << endl;
}