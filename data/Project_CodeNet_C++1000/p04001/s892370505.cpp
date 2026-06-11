#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    string S;
    cin >> S;

    int n;
    const int nmax = 10;
    ll ans, sum;
    string smemo;

    n = (int)S.length();

    ans = 0;
    rep(i, 1 << (n - 1)){
        sum = 0;
        smemo = "";
        bitset<nmax> bit(i);
        rep(j, n){
            smemo += S[j];
            if(bit.test(j)){
                sum += stol(smemo);
                smemo = "";
            }
            if(j == n - 1){
                sum += stol(smemo);
            }

        }
        ans += sum;
    }
    cout << ans << endl;
    
    return 0;
}
