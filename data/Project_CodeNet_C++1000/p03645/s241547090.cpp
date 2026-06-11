#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        A[i] = a;
        B[i] = b;
    }

    set<int> transits;
    int trA = 0, trB = 0;
    for(int i =0 ; i < M; i++){
        if(A[i] == 1) {
            transits.insert(B[i]);
            trA++;
        }
        if(B[i] == N) {
            transits.insert(A[i]);
            trB++;
        }
    }

    if(transits.size() == (trA+trB)){
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << "POSSIBLE" << endl;
    }

    return 0;
}
