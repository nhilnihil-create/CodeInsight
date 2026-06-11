#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    string a, b, c; cin >> a >> b >> c;
    int an = a.size() == 1 ? 0 : a.size() - 1;
    int bn = b.size() == 1 ? 0 : b.size() - 1;
    if(a[an] == b[0] && b[bn] == c[0]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
