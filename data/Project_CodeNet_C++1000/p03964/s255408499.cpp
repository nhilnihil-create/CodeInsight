#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    vector<int> t(N), a(N);
    for(int i=0; i<N; i++) {
        cin >> t[i] >> a[i];
    }

    ll T = 1, A = 1;
    for(int i=0; i<N; i++) {
        ll n = max((T+t[i]-1)/t[i], (A+a[i]-1)/a[i]);
        A = n * a[i], T = n * t[i];
    }
    cout << A + T << endl;
}