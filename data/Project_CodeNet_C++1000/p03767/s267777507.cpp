#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int N;
    
    cin >> N;

    long long int M = 3.0*N;
    long long int a[M];
    for (int i = 0; i < M; i++){
        cin >> a[i];
    }
    
    sort(a, a + M, greater<long long int>());
    for (int i = 0; i < M; i++){
    }

    long long int ans = 0;
    for (long int i = 0; i <= 2*N; i++){
        if (i % 2 == 1){
            ans += a[i];
        }
    }

    cout << ans << endl;
}