#include <bits/stdc++.h>
using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define CALL(c) (c).cbegin(), (c).cend()
#define RALL(c) (c).rbegin(), (c).rend()
#define CRALL(c) (c).crbegin(), (c).crend()
#define REP(i, n) for (int i = 0; i < static_cast<int>(n); i++)
#define FOR(i, s, n) for (int i = s; i < static_cast<int>(n); i++)
#define PSORT(s,p,e) partial_sort((s), next((s), (p)), (e))
#define VIEW(v,t) for_each((v).begin(), (v).end(), [](t& a) { cout << a << " "; }); cout << endl;

using PII = pair<int, int>;
using LL = long long;
using ULL = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using V2 = vector<vector<T>>;

const ULL fr = 1000000007;

int N;
V<ULL> T;
V<ULL> A;
V<ULL> X;
V<ULL> C;

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) {
        ULL x;
        cin >> x;
        T.push_back(x);
    }
    REP(i, N) {
        ULL x;
        cin >> x;
        A.push_back(x);
    }

    ULL mt = T[0];
    ULL ma = A[0];
    X.push_back(min(T[0], A[0]));
    FOR(i,1,N) {
        if(mt < T[i]) mt = T[i];
        if(ma < A[i]) ma = A[i];
        if(T[i-1] > T[i] || A[i-1] < A[i]) {
            cout << 0 << "\n";
            return 0;
        }
        if(T[i-1] < T[i] && T[i] > A[i]) {

        }
        if(A[i-1] > A[i] && A[i-1] > T[i-1]) {
            cout << 0 << "\n";
            return 0;
        }
        X.push_back(min(T[i], A[i]));
    }

    if (mt != ma) {
        cout << 0 << "\n";
        return 0;
    }


    REP(i, N) {
        int ct = 0;
        C.push_back(1);
        int e = C.size()-1;

        FOR(j,i+1,N) {
            if(X[i] != X[j]) break;
            ct++;
        }
        int y = ct;
        if(A[i+ct] == T[i+ct]) y--;
        REP(j,y) {
            C[e] *= (X[i] % fr);
            C[e] = (C[e] % fr);
        }

        i += ct;
    }

    ULL ans = 1;
    REP(i, C.size()) {
        ans *= (C[i] % fr);
        ans = (ans % fr);
    }

    cout << ans << "\n";
}