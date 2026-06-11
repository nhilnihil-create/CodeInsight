#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
#include <list>
#include <deque>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// const int MOD = 1000000007;
// const ll INF = 1LL << 60;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) {return a / GCD(a, b) * b;}

int main()
{
    ll N,K;
    cin >> N >> K;
    vector<pair<ll,ll> > ab(N);
    for(int i = 0; i < N; i++) cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(),ab.end());
    ll count = 0;
    for(int i = 0; i < N; i++)
    {
        count += ab[i].second;
        if (count >= K){
            cout << ab[i].first << endl;
            return 0;
        }
    }
}