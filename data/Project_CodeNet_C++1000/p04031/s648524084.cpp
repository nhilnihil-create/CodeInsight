#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
int main(){
    int N;
    cin >> N;
    vector<int>a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int ans = INF;
    for(int i = -100; i <= 100; i++) {
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            cnt+=(i-a[j])*(i-a[j]);
        }
        ans = min(ans,cnt);
    }
    cout << ans << endl;
}