#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;


int main(){
    int N;
    cin >> N;
    vector<int> T(N), A(N);
    rep(i, N) cin >>T[i] >> A[i];

    ll t = 1, a = 1;

    for(int i = 0; i < N; i++){
        ll n = max((t + T[i] - 1) / T[i] , (a + A[i] - 1) / A[i]);
        t = n * T[i]; a = n * A[i];
//        cout << "i:" << i << " " << t << " " << a << endl;
    }
    cout << t + a << endl;
    return 0;
}
