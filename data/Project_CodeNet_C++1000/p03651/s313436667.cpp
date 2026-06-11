#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    int ma = 0;
    rep(i, N){
        cin >> A[i];
        ma = max(ma, A[i]);
    }
    sort(A.begin(), A.end());

    if(K > ma){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int now = A[0];
    bool ok = true;
    while(ok){
        ok = false;
        int nex = now;
        rep(i, N){
            int a = A[i] % now;
            if(a == 0)continue;
            ok = true;
            nex = min(nex, a);
        }
        now = nex;
    }

    if(K % now == 0){
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}