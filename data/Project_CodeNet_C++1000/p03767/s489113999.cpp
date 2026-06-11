#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    ll N , ans = 0;
    cin >> N;
    vector <ll> a(3 * N);
    for(int i = 0; i < 3 * N; i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    for(int i = N; i <= 3 * N - 2; i+=2){
        ans+=a[i];
    }
    cout << ans << endl;
}