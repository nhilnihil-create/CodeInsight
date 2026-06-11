#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)

int K, T;
int A[100010];

signed main()
{
    cin >> K >> T;
    rep(i, T)cin >> A[i];
    sort(A, A + T);
    reverse(A, A + T);
    if(A[0] <= K / 2)cout << 0 << endl;
    else cout << K - 1 - (K - A[0]) * 2 << endl;
    return 0;
}
