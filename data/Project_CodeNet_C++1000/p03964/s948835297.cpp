#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll ZERO = 0;
const ll INF = 1e14;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;

int main() {
    int N;
    cin >> N;
    vector<P> vec(N);
    for(int i = 0;i < N;i++) {
        ll A,B;
        cin >> A >> B;
        vec.at(i) = P(A, B);
    }
    ll A = 1;
    ll B = 1;
    for(int i = 0;i < N;i++) {
        ll C = max((A + vec[i].first - 1) / vec[i].first,(B + vec[i].second - 1) / vec[i].second);
        A = vec[i].first * C;
        B = vec[i].second * C;
    }
    cout << A + B << endl;
}