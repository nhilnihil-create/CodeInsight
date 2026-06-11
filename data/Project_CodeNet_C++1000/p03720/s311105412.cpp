#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    vector<int> B(M);
    for(int i=0; i<M; i++){
        cin >> A.at(i) >> B.at(i);
    }

    int num[55] = {0};
    for (int i = 0; i < M; ++i) {
        num[A[i]]++;
        num[B[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        cout << num[i] << endl;
    }
}