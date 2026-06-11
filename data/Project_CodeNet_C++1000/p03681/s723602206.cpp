#include <iostream>
using namespace std;
const int INF = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    if(abs(N - M) > 1){
        cout << 0 << '\n';
        return 0;
    }
    long long ans = 1;
    for(int i = 1; i <= N; ++i) {
        ans *= i;
        ans %= INF;
    }
    for(int i = 1; i <=M; ++i) {
        ans *= i;
        ans %= INF;
    }
    if(N == M){
        ans *= 2;
        ans %= INF;
    }
    cout << ans << endl;
    return 0;
}