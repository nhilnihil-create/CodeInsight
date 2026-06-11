#include<iostream>
using namespace std;

int main(){
    int N,M;
    cin >> N;
    int T[N];
    for(int i=0; i<N; i++){
        cin >> T[i];
    }
    cin >> M;
    int P[M], X[M];
    for(int i=0; i<M; i++){
        cin >> P[i] >> X[i];
    }

    int total = 0;
    for(int i=0; i<N; i++){
        total += T[i];
    }
    const int INITIAL_TOTAL_TIME = total;

    for(int i=0; i<M; i++){
        cout << (INITIAL_TOTAL_TIME - T[P[i]-1] + X[i]) << '\n';
    }



}

