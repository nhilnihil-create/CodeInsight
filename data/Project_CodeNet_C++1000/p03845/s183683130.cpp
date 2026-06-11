#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, M;
    cin >> N;
    vector<int> T(N);
    for(int i=0; i<N; i++){
        cin >> T[i];
    }
    cin >> M;
    typedef pair<int, int> effect;
    vector<effect> X(M);
    for(int i=0; i<M; i++){
        int index, val;
        cin >> index >> val;
        X[i] = effect(index-1, val);
    }

    int sum=0;
    for(int i=0; i<N; i++){
        sum += T[i];
    }

    for(int i=0; i<M; i++){
        effect eff = X[i];
        int ans = sum - T[eff.first] + eff.second;
        cout << ans << "\n";
    }

    return 0;
}