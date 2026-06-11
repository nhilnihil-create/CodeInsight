#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    long long count;
    count = A[0] - 1;
    long long initial = 2;
    for (int i = 1; i < N; i++){
        if (A[i] == initial) initial += 1;
        else count += (A[i] - 1) / initial;
    }
    cout << count << '\n';

    return 0;
}