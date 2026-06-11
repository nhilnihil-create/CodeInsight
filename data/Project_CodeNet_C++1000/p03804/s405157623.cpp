#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#pragma endregion Macros

int N, M;

bool f(vector<string> a, vector<string> b, int h, int w){
    for (int i=0;i<M;i++){
        for (int j = 0; j < M; j++){
            if(a[h+i][w+j] != b[i][j]) return false;
        }
    }
    return true;
}

int main()
{
    cin >> N >> M ;
    vector<string> A(N),B(M);
    rep(i,N) cin >> A[i];
    rep(i, M) cin >> B[i];

    for (int h = 0; h <= N - M;h++){
        for (int w = 0;w<=N-M;w++){
            if(f(A,B,h,w)){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
