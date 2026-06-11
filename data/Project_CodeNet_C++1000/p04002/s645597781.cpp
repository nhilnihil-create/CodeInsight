#include <bits/stdc++.h>
using namespace std;

long long ans[15];
const int N = 1e6 + 10;

int main()
{
    long long h, w, node[N], inf = 1e9 + 7, n, a, b, cnt = 0;
    cin >> h >> w >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        for(int i = -2; i <= 0; i++){
            for(int j = -2; j <= 0; j++){
                if(a + i >= 1 && b + j >= 1 && a + i <= h - 2 && b + j <= w - 2){
                    node[cnt] = inf * (a + i) + (b + j);
                    cnt++;
                }
            }
        }
    }
    sort(node, node + cnt);
    long long tmp = 1, zero = (h - 2) * (w - 2);
    for(int i = 0; i <= cnt - 1; i++){
        if(node[i + 1] == node[i]) tmp++;
        else{
            ans[tmp]++;
            tmp = 1;
            zero--;
        }
    }
    cout << zero << endl;
    for(int i = 1; i <= 9; i++) cout << ans[i] << endl;
}