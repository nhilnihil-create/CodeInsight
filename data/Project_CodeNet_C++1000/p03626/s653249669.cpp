#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>
#include <utility>
#include <deque>
#include <queue>


using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
const ll MOD = 1e9 + 7;
vi alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z' };


int main() {
    int N;
    cin >> N;
    string S1, S2;
    cin >> S1 >> S2;
    vi frag(N, 0);
    ll ans = 1;
    rep(i, N) {
        if (S1[i] == S2[i]) {
            frag[i]++;
        }
    }
    int fragg;
    if (frag[0] == 0 ) {
        ans *= 6;
        fragg = 1;
    }
    else if (frag[0] == 1) {
        ans *= 3;
        fragg = 0;
    }
    repp(i, N-1) {
        if (fragg != 0) {
            fragg--;
            continue;
        }

        if (frag[i] == 0 && frag[i - 1] == 0) {
            fragg = 1;
            ans *= 3;
            ans = ans % MOD;
        }
        else if (frag[i] == 0 && frag[i - 1] == 1) {
            fragg = 1;
            ans *= 2;
            ans = ans % MOD;
        }
        else if (frag[i] == 1 && frag[i - 1] == 0) {
            fragg = 0;
        }
        else {
            fragg = 0;
            ans *= 2;
            ans = ans % MOD;
        }
    }
    cout << ans << endl;
}