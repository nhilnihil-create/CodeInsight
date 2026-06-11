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
    REP(i,N) {
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    int cnt = 0;
    ll total = 0;
    REP(i,N-1) {
        total += A[i];
        if(2*total >= A[i+1]) cnt++;
        else cnt = 0;
    }
    cout << cnt+1 << endl;
}