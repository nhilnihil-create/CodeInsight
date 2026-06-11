#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(100000);
    vector<int> B(N);
    for(int i=0; i<N; i++) cin >> B[i];

    for(int a : B) {
        if(a-1 >= 0) A[a-1]++;
        A[a]++;
        if(a+1 <= N) A[a+1]++;
    }
    sort(A.begin(), A.end());
    cout << A[99999] << endl;
}