#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <random>
#include <cassert>
#include <numeric>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;

ll y[10000005];

int main() {
    int n; cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i] >> b[i];

    ll sum = 0;
    for(int i = n-1; i >= 0; i--){
        a[i] += sum;
        if(!(a[i]%b[i])) continue;
        else {
            a[i] %= b[i];
            sum += b[i] - a[i];
        }
    }
    cout << sum << endl;
}
