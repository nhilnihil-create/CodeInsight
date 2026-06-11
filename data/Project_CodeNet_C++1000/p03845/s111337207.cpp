#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> T(N);
    int sum = 0;
    for(int i = 0; i < N; ++i){
        cin >> T[i];
        sum += T[i];
    }
    int M; cin >> M;
    vector<int> ans(M);
    for(int i = 0; i < M; ++i){
        int p,x;
        cin >> p >> x;
        p--;
        ans[i] = sum - T[p] + x;
    }
    for(int i = 0; i < M; ++i) cout << ans[i] << endl;
    return 0;
}