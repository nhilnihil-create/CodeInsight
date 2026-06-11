#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;
const double PI=3.1415926535897932;

ll N, ans=0, tmp=1;
vector<ll> A;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<N;i++) {
        if(A[i]==tmp&&i!=0) {
            tmp++;
            continue;
        }
        ans += (A[i]-1)/tmp;
        if(i==0) tmp++;
    }
    cout << ans << endl;
    return 0;
}