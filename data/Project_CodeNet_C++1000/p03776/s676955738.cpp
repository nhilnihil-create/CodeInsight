#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    double mean = 0;
    for (int i = 0; i < A; i++) mean += v[i];
    mean /= A;
    ll com = 0;
    if (A < N && v[A] == v[A-1]) {
        int l = N;
        int r = 0;
        for (int i = 0; i < N; i++) {
            if (v[i] == v[A]) {
                l = min(l, i);
                r = max(r, i+1);
            }
        }
        if (v[0] != v[A]) {
            com = 1;
            for (int i = 1; i <= A-l; i++) {
                com = com * (r-l+1-i) / i;
            }
        } else {
            com = 0;
            for (int i = A; i <= min(r, B); i++) {
                ll c = 1;
                for (int j = 1; j <= i; j++) {
                    c = c * (r+1-j) / j;
                }
                com += c;
            }
        }
    } else {
        com = 1;
    }
    printf("%.10lf\n", mean);
    printf("%lld\n", com);
    
}