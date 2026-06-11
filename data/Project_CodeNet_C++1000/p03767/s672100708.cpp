#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    cin >> N;
    vector<long long> A(3 * N);
    for(long long i  = 0; i < 3 * N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    long long ans = 0;
    for(long long i = 0; i < N; i++){
        ans += A.at(N + 2 * i);
    }
    cout << ans << endl;
    return 0;
}