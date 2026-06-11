#include <bits/stdc++.h>
using namespace std;
using ll = long long; // ll は long long　と同じとする。
int main () {
    int N;
    cin >> N;
    int K = N / 10;
    if(K == 9 || N - K * 10 == 9){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
