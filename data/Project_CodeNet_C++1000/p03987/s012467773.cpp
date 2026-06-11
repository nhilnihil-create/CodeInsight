#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;
const double PI=3.1415926535897932;

ll N, ans=0, tmp=0;
vector<ll> A, FV, BV;
set<ll> F, B;

signed main(){
    cin >> N;
    A.resize(N);
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        a--;
        A[a] = i;
    }
    F.insert(-1);
    F.insert(N);
    for(int i=0;i<N;i++) {
        set<ll>::iterator itr = F.lower_bound(A[i]);
        BV.push_back(*itr);
        itr--;
        FV.push_back(*itr);
        F.insert(A[i]);
    }
    for(int i=0;i<N;i++) {
        //ans += 1+COM(BV[i]-FV[i]-1, 2)-COM(A[i]-FV[i]-1, 2)-COM(A[i]-BV[i]-1, 2);
        tmp = 1+max(0LL, BV[i]-FV[i]-1)*max(0LL, BV[i]-FV[i]-2)/2-max(0LL, A[i]-FV[i]-1)*max(0LL, A[i]-FV[i]-2)/2-max(0LL, BV[i]-1-A[i])*max(0LL, BV[i]-2-A[i])/2;
        ans += (i+1)*tmp;
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}