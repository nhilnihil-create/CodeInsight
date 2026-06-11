#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<int>a(N);
    vector<int>b(N);
    vector<int>c(M);
    vector<int>d(M);
    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> c[i] >> d[i];
    }
    for(int i = 0; i < N; i++) {
        int cnt = 1e9;
        int ans = 0;
        for(int j = 0; j < M; j++) {
            if(abs(a[i]-c[j])+abs(b[i]-d[j]) < cnt) {
                ans = j+1;
                cnt = abs(a[i]-c[j])+abs(b[i]-d[j]);
            }
        }
        cout << ans << endl;
    }
}