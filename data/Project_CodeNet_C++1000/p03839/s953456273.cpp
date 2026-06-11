#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;
const double PI=3.1415926535897932;

ll N, K, ans=0, tmp1=0, tmp2=0, sum1=0, sum2=0;
vector<ll> A, S, L, R, SS;

signed main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    S.resize(N, 0);
    SS.resize(N, 0);
    L.resize(N, 0);
    R.resize(N, 0);
    S[0] = A[0];
    for(int i=1;i<N;i++) {
        S[i] = S[i-1]+A[i];
    }
    SS[0] = S[K-1];
    for(int i=1;i<=N-K;i++) {
        SS[i] = S[i+K-1]-S[i-1];
    }
    for(int i=1;i<N;i++) {
        L[i] = L[i-1]+max(0LL, A[i-1]);
        //cout << L[i] << endl;
    }
    //cout << endl;
    for(int i=1;i<N;i++) {
        R[N-i-1] = R[N-i]+max(0LL, A[N-i]);
        //cout << R[N-i-1] << endl;
    }
    //cout << endl;
    for(int i=0;i<=N-K;i++) {
        ans = max(ans, L[i]+R[i+K-1]+max(0LL, SS[i]));
        //cout << SS[i] << endl;
        //cout << L[i] << " " << R[i+K-1] << " " << max(0LL, SS[i]) << " " << ans << endl;
    }
    //cout << endl;
    cout << ans << endl;
    return 0;
}