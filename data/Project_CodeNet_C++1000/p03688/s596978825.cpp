#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100100;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    
    int nin = *min_element(a.begin(), a.end());
    int nax = *max_element(a.begin(), a.end());
    
    if (nin + 1 < nax) {
        cout << "No" << endl;
    } else if (nin + 1 == nax) {
        auto f = [&] (int x) { return x == nin; };
        int nini = count_if(a.begin(), a.end(), f);
        int ncc = nax - nini; // 連結成分の個数
        if (n-nini >= ncc*2 && nini <= nin) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if (nin*2 <= n || nin  == n-1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}