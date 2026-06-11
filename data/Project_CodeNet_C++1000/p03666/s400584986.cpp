#include <iostream>
using namespace std;

int main(){
    long long N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    // 深さN-1のノードに対して判定処理を行う。
    for(long long i = 0; i < N; ++i){
        // lower_bound
        long long lb = A + i * C + (i - (N - 1)) * D;
        // upper_bound
        long long ub = A + (i - (N - 1)) * C + i * D;
        if(lb <= B && B <= ub){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}