#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int A, B;
    cin >> A >> B;
    if(A==1) A+=14;
    if(B==1) B+=14;
    bool c1 = A>B;
    bool c2 = A<B;
    bool c3 = A==B;
    if(c1) cout << "Alice" << '\n';
    else if(c2) cout << "Bob" << '\n';
    else if(c3) cout << "Draw" << '\n';
}
