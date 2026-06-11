#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, x;
    cin >> N >> x;

    ll a[N];
    for(int i=0; i<N; i++) cin >> a[i];

    ll ans = 0;
    for(int i=1; i<N; i++){
        ll sum = a[i] + a[i-1];
        if(sum <= x) continue;

        ll d = sum - x;
        ans += d;
        if(a[i] >= d) a[i] -= d;
        else{
            a[i-1] -= (d-a[i]);
            a[i] = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
