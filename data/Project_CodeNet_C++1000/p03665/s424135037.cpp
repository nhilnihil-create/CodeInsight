#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    ll N , P , count = 0 , ans = 1;
    cin >> N >> P;
    vector <int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(A[i] % 2 == 1){
            count++;
        }
    }
    if(count == 0){
        if(P == 0){
            for(int i = 0; i < N; i++){
                ans *= 2;
            }
            cout << ans << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    else{
        for(int i = 0; i < N - 1; i++){
            ans *= 2;
        }
        cout << ans << endl;
    }
}
