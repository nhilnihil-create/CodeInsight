#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, X, Y,sum=0;
    cin >> N >> K >> X >> Y;
    if(N < K){
        cout << N*X << endl;
    }
    else {
        sum = K*X;
        sum = sum + (N-K)*Y;
        cout << sum << endl;
    }

}