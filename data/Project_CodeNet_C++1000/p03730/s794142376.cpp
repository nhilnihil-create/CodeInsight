#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    for(int i=1;i<=100;++i){
        if(A*i%B == C){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
