#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;

    int total = 0;

    if(N < K){
        cout << N * X << endl;
        return 0;
    }

    total += K * X;
    total += (N - K) * Y;

    cout << total << endl;
}