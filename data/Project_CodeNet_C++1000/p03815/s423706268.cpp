#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

int main() {
    LL x;
    cin >> x;
    LL p = x/11;
    if(x - p*11 == 0) {
        cout << 2*p << endl;
    }else if(x - p*11 <= 6){
        cout << 2*p + 1 << endl;
    }else{
        cout << 2*p + 2 << endl;
    }
    return 0;
}
