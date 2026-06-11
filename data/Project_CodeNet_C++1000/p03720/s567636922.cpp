#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, M, a, b;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        A.at(a - 1)++;
        A.at(b - 1)++;
    }
    for(int i = 0; i < N; i++){
        cout << A.at(i) << endl;
    }
    return 0;
}