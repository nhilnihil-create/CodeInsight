#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;


int main(){ 
    Int N; cin >> N;
    vector<int> p(N);
    rep(i,N) {
        cin >> p[i];
        p[i]--;
    }

    vector<Int> A(N), B(N);
    rep(i,N){
        A[i] = 30000 * (i+1);
        B[N-i-1] = 30000 * (i+1);
    }

    rep(i,N) A[p[i]] += i;

    rep(i,N) cout << A[i] << " ";
    cout << endl;
    rep(i,N) cout << B[i] << " ";
    cout << endl;

}
