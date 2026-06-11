#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int N;
long long A[MAXN];
void solve(){
    sort(A, A + 3 * N, greater<int>());
    long long sum = 0, cnt = 0;
    for(int i = 1; cnt < N; i += 2, cnt++)
        sum += A[i];
    cout << sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    //cin >> test;
    while(test--){
        cin >> N;
        int i = 0;
        for(i = 0; i < 3 * N; i++)
            cin >> A[i];
        solve();
    }
    return 0;
}