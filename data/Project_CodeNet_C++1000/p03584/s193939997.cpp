#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    for(int i=0; i<N; i++) cin >> A[i] >> B[i];

    bitset<30> b(K);
    ll ans = 0;
    for(int i=0; i<N; i++){
        bool ok = true;
        for(int j=0; j<30; j++){
            if(!b[j] & (A[i]>>j) & 1){
                ok = false; break;
            }
        }
        if(ok) ans += B[i];
    }
    // cout << ans << endl;

    for(int i=0; i<30; i++){
        if(!b[i]) continue;

        ll sum = 0;
        for(int j=0; j<N; j++){
            bool ok = !((A[j]>>i) & 1);
            for(int k=i+1; k<30; k++){
                if(!b[k] & (A[j]>>k) & 1){
                    // cout << "\t" << i << " " << j << " " << k << endl;
                    ok = false; break;
                }
            }
            if(ok) sum += B[j];
        }
        // cout << i << " " << sum << endl;

        ans = max(ans, sum);
    }

    cout << ans << endl;
}