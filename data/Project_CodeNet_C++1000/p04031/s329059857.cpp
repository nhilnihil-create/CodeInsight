#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve(){
    ll n, i, minn = 1010000000000000, sum;
    cin >> n;
    vector <ll> vec(n);
    for(auto &i : vec){
        cin >> i;
    }
    sort(vec.begin(), vec.end());
    for(i = vec[0]; i <= vec[n - 1]; i++){
        sum = 0;
        for(auto j : vec){
            sum += ((i - j) * (i - j));
        }
        minn = min(sum, minn);
    }
    cout << minn << "\n";
    return 0;
 }

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
