#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int main() {
    int N; cin>>N;
    vector<ll> p(N);
    for (int i = 0; i < N; ++i) {
        cin>>p[i]; --p[i];
    }

    vector<ll> a(N),b(N);
    for (int i = 0; i < N; ++i) {
        a[i]=40000ll*(i+1);
        b[i]=40000ll*(N-i);
    }

    for (int i = 0; i < N; ++i) {
        a[p[i]]+=(ll)i;
    }

    for (int i = 0; i <N-1; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<a[N-1]<<endl;

    for (int i = 0; i <N-1; ++i) {
        cout<<b[i]<<" ";
    }
    cout<<b[N-1]<<endl;

    return 0;
}
