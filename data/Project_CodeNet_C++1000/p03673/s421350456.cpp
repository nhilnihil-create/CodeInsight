#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    vector<int> V(N), W(N);
    for(int i=0; i<N; i++) cin >> V[i];
    for(int i=0; i<N; i++) {
        if(i % 2 == 0) {
            W[i/2] = V[N-i-1];
        }
        else {
            W[N-1-i/2] = V[N-i-1];
        }
    }
    for(int i=0; i<N; i++) cout << W[i] << " " ;
}