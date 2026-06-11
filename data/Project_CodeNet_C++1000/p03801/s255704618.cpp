#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
vector<pair<ll,ll>> A;
vector<ll> B;
set<ll> S;
priority_queue<ll, vector<ll>, greater<ll>> Q;

signed main(){
    cin >> N;
    S.insert(0);
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        S.insert(a);
        A.push_back(make_pair(a, i));
    }
    sort(A.begin(), A.end());
    set<ll>::iterator itr=S.end();
    itr--;
    ll tmp1, tmp2;
    B.resize(N, 0);
    while(itr!=S.begin()) {
        tmp1 = *itr;
        ll id1 = lower_bound(A.begin(), A.end(), make_pair(tmp1, 0LL))-A.begin();
        ll id2 = A.end()-lower_bound(A.begin(), A.end(), make_pair(tmp1, 0LL));
        itr--;
        tmp2 = *itr;
        Q.push(A[id1].second);
        B[Q.top()] += (tmp1-tmp2)*id2;
        //cout << "B[" << A[id1].second << "]=" << (tmp1-tmp2) << " " << id2 << endl;
    }
    for(int i=0;i<N;i++) {
        cout << B[i] << endl;
    }
    return 0;
}