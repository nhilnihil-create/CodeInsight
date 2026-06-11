#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

int main() {
    int N;
    cin >> N;
    map<ll, int> MP;
    rep(i, 0, N){
        ll tmp;
        cin >> tmp;
        MP[tmp]++;
    }
    ll ans = 0;
    for(auto & s : MP){
        ans += s.second%2;
    }
    cout << ans << endl;
    return 0;
}
