#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    int n = (int)A.size();
    cout << n - (1 - n % 2) << endl;
    return 0;
}
