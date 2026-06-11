#include <fstream>
#include <iostream>
// #include <cassert>

// BE CAREFUL WITH HASH TABLE & UNORDERED MAP
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define MOD 998244353
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= (a); i--)
#define RF0(i,b) RFO(i,0,b)
#define lli long long int
#define pii pair<int,int>
#define add(a,b) ((int) (((lli) (a) + (b))%MOD))
#define mul(a,b) ((int) (((lli) (a) * (b))%MOD))
#define PB emplace_back
#define F first
#define S second

// ifstream cin ("cinput.in");
// ofstream cout ("coutput.out");

int N, L;
int lens [100000];

// Helper Functions

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L;
    int msum = 0, ind = -1;
    F0R(i, N) {
        cin >> lens[i];
        if (i > 0) {
            if (lens[i] + lens[i-1] > msum) {
                msum = lens[i] + lens[i-1];
                ind = i;
            }
        }
    }
    if (msum < L) {cout << "Impossible\n"; return 0;}
    cout << "Possible\n";
    FOR(i, 1, ind) cout << i << '\n';
    RFO(i, ind, N) cout << i << '\n';
}