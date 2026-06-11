#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans1=0, ans2=0, tmp=0;
vector<ll> A, S;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    S.resize(N);
    S[0] = A[0];
    tmp=1;
    for(int i=0;i<N-1;i++) {
        if(tmp>0) {
            ans1 += max(tmp-S[i], 0LL);
            S[i] += max(tmp-S[i], 0LL);
        }
        else {
            ans1 += max(S[i]-tmp, 0LL);
            S[i] -= max(S[i]-tmp, 0LL);
        }
        S[i+1] = S[i] + A[i+1];
        tmp *= (-1);
    }
    if(tmp>0) {
        ans1 += max(tmp-S[N-1], 0LL);
        S[N-1] += max(tmp-S[N-1], 0LL);
    }
    else {
        ans1 += max(S[N-1]-tmp, 0LL);
        S[N-1] -= max(S[N-1]-tmp, 0LL);
    }
    S.resize(N);
    S[0] = A[0];
    tmp=-1;
    for(int i=0;i<N-1;i++) {
        if(tmp>0) {
            ans2 += max(tmp-S[i], 0LL);
            S[i] += max(tmp-S[i], 0LL);
        }
        else {
            ans2 += max(S[i]-tmp, 0LL);
            S[i] -= max(S[i]-tmp, 0LL);
        }
        S[i+1] = S[i] + A[i+1];
        tmp *= (-1);
    }
    if(tmp>0) {
        ans2 += max(tmp-S[N-1], 0LL);
        S[N-1] += max(tmp-S[N-1], 0LL);
    }
    else {
        ans2 += max(S[N-1]-tmp, 0LL);
        S[N-1] -= max(S[N-1]-tmp, 0LL);
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}