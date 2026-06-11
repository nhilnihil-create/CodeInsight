#include <bits/stdc++.h>
using namespace std;
int main(){
    int64_t N, M;
    cin >> N >> M;
    if(N * 2 >= M) cout << M / 2 << endl;
    else cout << N + (M - 2 * N) / 4 << endl;
}