#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int w, a, b; cin >> w >> a >> b;
    if(w + a < b){
        cout << b - w - a << endl;
    }else if(b + w < a){
        cout << a - w - b << endl;
    }else if(w == b){
        cout << 0 << endl;
    }else{
        int x = min(abs((a + w) - b), abs(a - (b + w)));
        cout << x << endl;
    }
}
