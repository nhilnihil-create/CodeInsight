#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, T;
    cin >> N >> T;
    long long ans = 0;
    vector<int> t(N); for(int i = 0; i < N; ++i) cin >> t[i];
    for(int i = 0; i < N-1; ++i){
        ans += min(T, t[i+1] - t[i]);
    }
    ans += T;
    cout << ans << endl;
    return 0;
}