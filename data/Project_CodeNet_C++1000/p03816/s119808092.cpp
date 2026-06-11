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
    int N;
    cin >> N;
    map<int, int> A;
    REP(i, N) {
        int x;
        cin >> x;
        A[x]++;
    }
    int c = 0;
    int d = 0;
    for(auto i : A) {
        if(1 < i.second) {
            if(i.second%2 == 0) {
                c++;
            }else{
                d++;
            }
        }else{
            d++;
        }
    }
    if(c%2 == 0) {
        cout << c + d << endl;
    }else{
        cout << c + d - 1 << endl;
    }
    return 0;
}
