#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int A, B;
    cin >> A >> B;
    if(A+B >=10){
        cout << "error" << endl;
    } else {
        cout << A+B << endl;
    }
}
