#include <bits/stdc++.h>
using namespace std;

void success(){
    cout << "Yes" << endl;
    exit(0);
}
void fail(){
    cout << "No" << endl;
    exit(0);
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    if(A[N-1] - A[0] >= 2) fail();
    if(A[0] == A[N-1] && A[0] == N-1) success();

    int one = 0;
    for(int i=0; i<N; i++) if(A[i] != A[N-1]) one++;
    int more_cat = N - one;
    int more_col = A[N-1] - one;
    if(more_col <= 0) fail();
    if(more_cat < 2*more_col) fail();
    success();
}