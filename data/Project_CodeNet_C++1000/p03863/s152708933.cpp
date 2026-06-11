#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string s; cin >> s;
    bool res = false;
    bool even = s.size() % 2 == 0;
    res = (s.at(0) == s.at(s.size() - 1)) ^ even;
    
    if (res) {
      cout << "Second" << endl;
    } else {
      cout << "First" << endl;
    }
}
