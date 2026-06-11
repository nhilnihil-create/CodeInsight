#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int (i)=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1000000007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }


int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    REP(i, N) cin >> A[i];

    long long ans = 0;
    long long mx = 0;
    REP(i, N){
        if(A[i] >= mx + 2){
            long long cnt = (A[i]-1)/(mx+1);
            ans += cnt;
            A[i] -= cnt * (mx+1);
            if(mx == 0) mx = 1;
        }else{
            mx = max(mx, A[i]);
        }
    }
    cout << ans << endl;
    return 0;
}