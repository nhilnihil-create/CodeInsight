#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<long long, long long>> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    cout << A[0].first + A[0].second << endl;
    return 0;
}