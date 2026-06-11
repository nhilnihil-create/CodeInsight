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

int main() {
    int T,K;
    cin >> K >> T;
    veci A(T);
    REP(i,T) cin >> A[i];
    sort(A.begin(),A.end());
    int max = A[T-1];
    int sum = 0;
    REP(i,T-1) sum += A[i];
    if(max-1 >= sum) cout << max-1-sum << endl;
    else cout << 0 << endl;
} 
