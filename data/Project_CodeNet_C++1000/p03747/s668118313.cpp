#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main()
{
    int N;
    ll L, T;
    cin >> N >> L >> T;
    vector<ll> X(N);
    vector<int> W(N);
    for (int n = 0; n < N; ++n) {
        cin >> X[n] >> W[n];
    }

    ll Col = 0LL;
    int Num; ll Pos;
    switch (W[0]) {
    case 1:
        for (int n = 1; n < N; ++n) {
            if (W[n] == 2) {
                Col += (2*T-X[n]+X[0]+L) / L;
            }
        }
        Num = Col % N;
        Pos = (X[0]+T) % L;
        break;
    case 2:
        for (int n = 1; n < N; ++n) {
            if (W[n] == 1) {
                Col += (2*T-L+X[n]-X[0]+L) / L;
            }
        }
        Num = (N*T-Col) % N;
        Pos = (X[0]-T+T*L) % L;
        break;
    }

    vector<ll> P;
    P.reserve(N);
    for (int n = 0; n < N; ++n) {
        switch (W[n]) {
        case 1:
            P.push_back((X[n]+T)%L);
            break;
        case 2:
            P.push_back((X[n]-T+L*T)%L);
            break;
        }
    }
    sort(P.begin(), P.end());

    int K = lower_bound(P.begin(), P.end(), Pos) - P.begin();
    if (P[K+1] == Pos && W[0] == 1) {
        ++K;
    }
    
    for (int n = 0; n < N; ++n) {
        cout << P[(K+n-Num+N) % N] << endl;
    }

    return 0;
}