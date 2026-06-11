#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
int N, T, A[MAX_N];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> T;
    for(int i=0;i<N;i++) cin >> A[i];

    int mn = 1e9 + 1, mx = -1e9;
    map<int, int> cnt;
    for(int i=0;i<N;i++){
        mx = max(mx, A[i]-mn); cnt[A[i]-mn]++;
        mn = min(mn, A[i]);
    }

    cout << cnt[mx] << endl;
    return 0;
}
