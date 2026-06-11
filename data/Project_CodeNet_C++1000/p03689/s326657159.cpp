
//----------------------------おまじない
#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")
//----------------------------
#define FOR(i,j,n) for (int i=(j);i<(n);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define REPN(i,n) for (int i=(n);i>0;i--)
#define I(n) scanf("%d", &(n))
#define LL(n) scanf("%lld", &(n))
#define pb(n) push_back((n))
#define mp(i,j) make_pair((i),(j))
#define eb(i,j) emplace_back((i),(j))
#include <bits/stdc++.h>
using namespace std;
//------------------------------typedef集
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vpi> vvpi;
typedef vector<vvi> vvvi;
typedef long long ll;
const int mod = 1000000009;

int h,w,hi,wi;

int main(){
    cin >> h >> w >> hi >> wi;
    if (h%hi == 0 && w%wi == 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    int hrep = h/hi + 1;
    int wrep = w/wi + 1;

    if (w%wi){// 横に構成
        REP(i,h) {
            REP(j,w){
                cout << ((j+1)%wi ? wrep : -1 * wrep * (wi-1) - 1);
                if (j!=w-1) cout << " ";
            }
            cout << endl;
        }
    } else {// 縦に構成
        REP(i,h) {
            REP(j,w){
                cout << ((i+1)%hi ? hrep : -1 * hrep * (hi-1) - 1);
                if (j!=w-1) cout << " ";
            }
            cout << endl;
        }
    }
}

