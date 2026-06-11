#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
 
int main() {
    long long N,A,B;
    cin >> N >> A >> B;
    long long sum = 0;
    long long X1,X2;
    cin >> X1;
    rep(i,N-1){
        cin >> X2;
        sum += min((X2-X1) * A,B);
        X1 = X2;
    } 
    cout << sum;

    return 0;
} 