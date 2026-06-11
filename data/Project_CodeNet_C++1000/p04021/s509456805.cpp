#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    
    vec<int> A(N);
    map<int,int> mp;
    rep(i, N) {
        cin >> A[i];
        mp[A[i]] = i%2;
    }

    sort(all(A));

    int ans = 0;
    rep(i,N){
        if(i%2 != mp[A[i]]) ++ans;
    }
    cout << (ans+1)/2 << '\n';
}
