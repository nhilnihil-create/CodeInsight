#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> A(N);
    int ans = 1e9;
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = -100; i < 101; ++i){
        int sum = 0;
        for(int j = 0; j < N; ++j){
            sum += (i-A[j])*(i-A[j]);
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}