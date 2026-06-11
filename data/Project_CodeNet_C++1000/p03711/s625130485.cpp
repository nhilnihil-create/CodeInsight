#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    string x, y;
    cin >> x >> y;

    auto check1 = [&](string a){
        return regex_search(a, regex("^1$|^3$|^5$|^7$|^8$|^10$|^12$"));
    };
    auto check2 = [&](string a){
        return regex_search(a, regex("^4$|^6$|^9$|^11$"));
    };

    if(check1(x)&&check1(y)){
        cout << "Yes" << endl;
        return 0;
    } else if(check2(x) && check2(y)){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}