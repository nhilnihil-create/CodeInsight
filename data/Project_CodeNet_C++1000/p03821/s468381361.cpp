#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
    int N; cin >> N;
    vecl A(N), B(N);
    REP(i,N) cin >> A[i] >> B[i];
    ll ans = 0;
    for(int i = N-1; i >= 0; i--) {
        A[i] += ans;
        if(A[i] == 0) continue;
        //cout << A[i] << endl;
        if(A[i] <= B[i]) {
            ans += B[i]-A[i];
        } else {
            if(A[i]%B[i] != 0) {
                ans += (A[i]/B[i]+1)*B[i]-A[i];
            }
        }
    }
    cout << ans << endl;
}
