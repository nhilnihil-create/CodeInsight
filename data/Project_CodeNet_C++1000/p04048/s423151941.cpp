#include<bits/stdc++.h>
using namespace std;

int main(){
    size_t N, X;
    cin >> N >> X;
    cout << 3 * (N - __gcd(N, X)) << endl;
    return 0;
}