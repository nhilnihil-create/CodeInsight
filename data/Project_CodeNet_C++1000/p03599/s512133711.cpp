#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    A = 100 * A;
    B = 100 * B;
    set<int> w;
    set<int> s;
    for (int i = 0; i <= F; i += A) for (int j = 0; j <= F; j += B)
        if(i+j<=F) w.insert(i+j);
    for (int i = 0; i <= F; i += C) for (int j = 0; j <= F; j += D)
        if(i+j<=F) s.insert(i+j);

    long double maxnoudo = 0;
    int maxWaterAll = 0;
    int maxSato     = 0;
    for (auto W : w) for(auto S:s){
        if(W+S>F) break;
        if(E*(W/100)<S) break;
        if((long double)W*maxnoudo < (long double)S){
            maxnoudo = (long double)S/W;
            maxWaterAll = W+S;
            maxSato = S;
        }

    }
    cout << (maxWaterAll==0?A:maxWaterAll) << " " << maxSato << endl;
}
