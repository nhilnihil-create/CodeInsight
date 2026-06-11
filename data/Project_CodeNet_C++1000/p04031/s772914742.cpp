#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N; cin >> N;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    long long ans = 1LL << 60;
    for(int i = -100; i <= 100; ++i){
        long long sum = 0;
        for(int j = 0; j < N; ++j){
            sum += (a[j]-i) * (a[j]-i);
        }
        if(sum < ans) ans = sum;
    }
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}