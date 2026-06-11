#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> A(N);
    Rep (i, N) {
        cin >> A[i];
    }

    ll now = 2, ans = A[0] - 1;
    Rep (i, N-1) {
        ans += ((A[i+1] + now - 1) / now - 1 );
        if (A[i+1] == now) {
            now++;
        }
        // cout << now << " " << ans << "\n";
    }

    cout << ans << "\n";
}