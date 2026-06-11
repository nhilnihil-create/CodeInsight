#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    string A, B, C;
    cin >> A >> B >> C;
    char al = A.back();
    char bs = *B.begin();
    char bl = B.back();
    char cs = *C.begin();
    if(al==bs&&bl==cs){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
