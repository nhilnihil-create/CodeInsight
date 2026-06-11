#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i< (n); ++i)
#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int main(){
    int X, t;
    cin >> X >> t;
    if(X-t <= 0) cout << 0 << endl;
    else cout << X - t << endl;
}