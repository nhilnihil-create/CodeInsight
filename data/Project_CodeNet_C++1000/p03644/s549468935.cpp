#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    int ans = 1;
    for(int i=2;i<=N;i*=2){
        ans = max(ans,i);
    }
    cout << ans << endl;
}
