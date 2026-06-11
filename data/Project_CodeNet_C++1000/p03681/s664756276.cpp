#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N,M;
    cin >> N >> M;
    
    if (abs(N-M) > 1){
        cout << 0 << endl;
        return 0;
    }

    long long count = 1;
    if (N == M){
        for (int i = 1; i <= N; i++) {
            count *= i;
            count %= 1000000007;
        }
        count *= count * 2;
        count %= 1000000007;
    }
    else {
        if (N > M){
           for (int i = 1; i <= M; i++) {
               count *= i;
               count %= 1000000007;
            } 
            count *= count;
            count %= 1000000007;
            count *= N;
            count %= 1000000007;
        }
        else {
            for (int i = 1; i <= N; i++) {
                count *= i;
                count %= 1000000007;
            } 
            count *= count;
            count %= 1000000007;
            count *= M;
            count %= 1000000007;
        }
    }
    cout << count << endl;
}