#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; (i) < (n); ++(i))
#define rep_from(i,m,n) for(int i = (m); (i) < (n); ++(i))
using namespace std;
typedef long long ll;

int main() {    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a*b == c*d) cout << a*b << endl;
    else {
        if(a*b < c*d) cout << c*d << endl;
        else cout << a*b << endl;
    }
    return 0;
}