#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
int main()
{
    int N;
    cin >> N;
    vector<int> T(N);
    int sum = 0;

    rep(i, N){
        cin >> T[i];
        sum += T[i];
    } 
    int M;
    cin >> M;
    rep(i, M){
        int P, X;
        int ans = 0;
        cin >> P >> X;
        ans = sum - T[P-1] + X;
        cout << ans << endl;
    }

    return 0;
}