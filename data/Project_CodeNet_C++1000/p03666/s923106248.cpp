#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
    int n;
    double a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    double f = abs(a-b);
    double t = (c+d)/2.0;
    double s = (d-c)/2.0;
    rep(i,n-1) {
        f = min(abs(f+t),abs(f-t));
    }
    if(f <= (n-1)*s) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}