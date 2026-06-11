#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define int long long
using namespace std;
signed main(){
    int N, K; cin >> N >> K;
    vector<long long> a(N), S1(N+1, 0), S2(N+1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        S1[i+1] = S1[i] + a[i];
        S2[i+1] = S2[i] + (a[i] >= 0 ? a[i] : 0);
    }
    long long res = -(1LL<<60);
    for (int i = 0; i + K <= N; ++i) {
        int left = i, right = i + K;
        long long tmp=(S2[left]-S2[0])+max(0LL, S1[right]-S1[left])+(S2[N]-S2[right]);
        res = max(res, tmp);
    }
    cout << res << endl;
}