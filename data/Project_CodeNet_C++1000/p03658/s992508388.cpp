#include <bits/stdc++.h>

using namespace std;

int main() {
    int N = 0;
    cin >> N;
    int K = 0;
    cin >> K;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    }

    int ans = 0;

    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    for (size_t i = 0; i < K; i++)
    {
        ans += A.at(i);
    }
    
    cout << ans << endl;



    return 0;
}