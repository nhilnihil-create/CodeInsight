#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    string s;
    cin >> s;

    int start = 1e9;
    int end = 0;
    rep(i,s.size()){
        if(s[i] == 'A') start=min(start,i);
        if(s[i] == 'Z') end=max(end,i);
    }
    cout << end - start +1 << endl;
}
