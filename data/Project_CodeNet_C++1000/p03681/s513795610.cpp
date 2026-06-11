//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

ll func[100001];
ll mod = 1000000007;

void setfunc(int i ) {
    func[0] = func[1] = 1;
    for(int j = 1; j<=i; ++j) {
        func[j+1] = func[j] * (j+1) % mod;
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    setfunc(max(n,m));
    if(abs(n-m)>1) {
        cout << 0 << endl;
        return 0;
    }

    if( (n + m) % 2 == 0 )
        cout << func[n] * func[m]  * 2  % mod << endl;
    else
        cout << func[n] * func[m]   % mod << endl;

    return 0;
}
