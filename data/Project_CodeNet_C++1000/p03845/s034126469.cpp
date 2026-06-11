#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M;
    long totalSec=0;
    cin >> N;
    long T[N];
    for(int i=0;  i<N; i++)
    {
        cin >> T[i];
        totalSec += T[i];
    }

    cin >> M;
    int P[M];
    long X[M];
    for(int i=0; i<M; i++)
    {
        cin >> P[i] >> X[i];
    }

    for(int i=0; i<M; i++)
    {
        cout << totalSec - T[P[i]-1] + X[i] << endl;
    }
    return 0;
}