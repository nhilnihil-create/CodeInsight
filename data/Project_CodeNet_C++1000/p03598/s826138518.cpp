#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N,K;
    cin >> N >> K;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int sum1 = abs(0-X[i]) * 2 + 0;
        int sum2 = abs(K-X[i]) * 2 + 0;
        if (sum1 <= sum2) {
            ans += sum1;
        }else{
            ans += sum2;
        }
    }
    cout << ans << endl;
}
