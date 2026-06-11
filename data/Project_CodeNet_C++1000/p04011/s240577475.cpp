#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N, K; cin >> N >> K;
    int X, Y; cin >> X >> Y;
    long long sum = 0;
    for(int i = 0; i < K && i < N; ++i) sum += X;
    for(int i = K; i < N; ++i) sum += Y;
    cout << sum << endl;

}

int main(){
    solve();
    return 0;
}