#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t K;
    cin >> K;
    int N = 50;
    int64_t q = K/N, r = K%N;
    vector<int64_t> ans(N, N-1+q);
    for(int s=0; s<r; s++) for(int i=0; i<N; i++) ans[i] += (i==s ? N : -1);
    cout << N << endl;
    for(int i=0; i<N; i++) cout << ans[i] << " \n"[i==N-1];
}
