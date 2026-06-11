#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){
    Int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    rep(i,N-1){ // 
        Int L = C*(N-1-i) - D*i;
        Int R = D*(N-1-i) - C*i;

        if(L <= B-A && B-A <= R){
            cout << "YES" << endl; return 0;
        }
    }

    cout << "NO" << endl;
}
