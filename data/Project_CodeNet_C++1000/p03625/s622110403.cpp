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
    vi A(N);
    rep(i, N) cin >> A[i];
    sort(A);
    riverse(A);
    ll frag1 = 0;
    ll frag2 = 0;
    int frag = 1;
    rep(i, N - 1) {
        if (A[i] == A[i + 1] && frag == 1) {
            frag1 = A[i];
            frag = 2;
            continue;
        }
        else if (frag == 2) {
            frag = 3;
            continue;
        }
        else if (A[i] == A[i + 1] && frag == 3) {
            frag2 = A[i];
            break;
        }
    }
    ll ans = frag1 * frag2;
    cout << ans << endl;
}