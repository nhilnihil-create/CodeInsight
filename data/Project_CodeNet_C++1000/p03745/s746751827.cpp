#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N; cin >> N;
    vecl A(N);
    REP(i,N) cin >> A[i];
    int ans =0;
    REP(i,N) {
        while (i+1 < N && A[i] == A[i+1]) ++i;
        if (i+1 < N && A[i] < A[i+1]) {
            while (i+1 < N && A[i] <= A[i+1]) ++i;
        }
        else if (i+1 < N && A[i] > A[i+1]) {
            while (i+1 < N && A[i] >= A[i+1]) ++i;
        }
        ans++;
    }
    cout << ans << endl;
}