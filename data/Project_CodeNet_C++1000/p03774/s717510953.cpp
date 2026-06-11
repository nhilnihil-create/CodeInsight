#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;


int main(){
    int N, M; cin >> N >> M;
    vector<int> A(N), B(N), C(M), D(M), ans(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];
    for(int i = 0; i < M; i++) cin >> C[i] >> D[i];

    for(int i = 0; i < N; i++){
        int dis = 1e9, cp = 1;
        int a = A[i], b = B[i];
        for(int j = 0; j < M; j++){
            int c = C[j], d = D[j];
            int temp = abs(c-a) + abs(d-b);
            if(temp < dis) {
                dis = temp;
                cp = j+1;
            }
        }
        ans[i] = cp;
    }
    for(auto x : ans) cout << x << endl;

}
