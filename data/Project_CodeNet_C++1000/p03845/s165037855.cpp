#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, M, temp, sum;

    cin >> N;

    int T[N] = {0};

    for(int i = 0; i < N; i++){
        cin >> T[i];
    }

    cin >> M;

    int P[M] = {0};
    int X[M] = {0};

    for(int i = 0; i < M; i++){
        cin >> P[i] >> X[i];

        sum = 0;
        temp = T[P[i] - 1];

        T[P[i] - 1] = X[i];

        for(int j = 0; j < N; j++){
            sum += T[j];

        }

        cout << sum << endl;
        T[P[i] - 1] = temp;
    }



    return 0;

}


