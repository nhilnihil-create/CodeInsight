#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

int main()
{
    int N, sum = 0;
    cin >> N;
    int A[N], B[N];
    rep(i, N)
        cin >> A[i] >> B[i];
        
    rep(i, N)
        sum += (B[i] - A[i]) + 1;
    
    cout << sum << endl;
}