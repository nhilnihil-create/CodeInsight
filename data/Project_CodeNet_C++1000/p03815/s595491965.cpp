#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    ll x; cin >> x; 
    ll ans = x;
    ans /= 11LL;

    if(x%11LL==0){
        cout << 2LL*ans << endl;
    }
    else if(x%11LL<=6){
        cout << 2LL*ans + 1LL << endl;
    }
    else cout << 2LL*ans + 2LL << endl;

    return 0;
}
