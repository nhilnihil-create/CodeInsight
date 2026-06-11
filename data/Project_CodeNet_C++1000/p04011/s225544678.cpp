#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,K,A,B;
    cin >> N >> K >> A >> B;
    if(N <= K){
        cout << N * A;
    }else{
        cout << K * A + (N-K) * B;
    }

    return 0;
}