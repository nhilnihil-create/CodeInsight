#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=1, tmp=0;
vector<ll> T, A, Tmins, Amins;

signed main(){
    cin >> N;
    Tmins.resize(N, 1);
    tmp = 0;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        T.push_back(a);
        if(tmp<a) {
            tmp = a;
            Tmins[i] = tmp;
        }
    }
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    reverse(A.begin(), A.end());
    Amins.resize(N, 1);
    tmp = 0;
    for(int i=0;i<N;i++) {
        if(tmp<A[i]) {
            tmp = A[i];
            Amins[i] = tmp;
        }
    }
    reverse(A.begin(), A.end());
    reverse(Amins.begin(), Amins.end());
    for(int i=0;i<N;i++) {
        A[i] = min(A[i], T[i]);
        Amins[i] = max(Amins[i], Tmins[i]);
        ans *= max(0LL,(A[i]-Amins[i]+1LL));
        ans %= MOD;
    }
    /*
    for(int i=0;i<N;i++) {
        cout << " " << A[i];
    }
    cout << endl;
    for(int i=0;i<N;i++) {
        cout << " " << Amins[i];
    }
    cout << endl;
    */
    cout << ans << endl;
    return 0;
}