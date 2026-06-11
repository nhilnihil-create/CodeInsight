#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N,M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);
    REP(i,N) cin >> A[i];
    REP(i,M) cin >> B[i];
    for(int i = 0; i <= N-M; i++) {
        for(int j = 0; j <= N-M; j++) {
            bool ok = true;
            for(int k = 0; k < M; k++) {
                for(int l = 0; l < M; l++) {
                    if(B[k][l] != A[i+k][j+l]) ok = false;
                }
            }
            if(ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}