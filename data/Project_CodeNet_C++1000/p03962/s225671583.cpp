#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int,int>;

int main() {
    int n;
    set<int> s;
    
    for (int i=0; i<3; ++i) {
        cin >> n;
        s.insert(n);
    }

    cout << s.size() << endl;
    return 0;
}