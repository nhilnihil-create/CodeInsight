#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;
const double PI=3.1415926535897932;

ll N, ans=0, tmp=0;
vector<ll> A, B;

signed main(){
    cin >> N;
    B.resize(N);
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        a--;
        A.push_back(1+(N+1)*i);
        B[a] = i+1+(N+1)*(N-1-a);
    }
    for(int i=0;i<N;i++) {
        cout << " " << A[i];
    }
    cout << endl;
    for(int i=0;i<N;i++) {
        cout << " " << B[i];
    }
    cout << endl;
    return 0;
}