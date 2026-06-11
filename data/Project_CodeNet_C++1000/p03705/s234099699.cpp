#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    ll N, A, B;
    cin >> N >> A >> B;
    ll mn = A * (N-1) + B;
    ll mx = A + B * (N - 1);
    ll ans = 0;
    ans = max(ans, mx - mn + 1);
    cout << ans << endl;
    return 0;
}