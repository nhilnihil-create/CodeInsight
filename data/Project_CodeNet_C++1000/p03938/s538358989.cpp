#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N;
    cin >> N;

    vector<int> p(N);
    for (auto &i : p) cin >> i, i--;

    vector<int> A(N), B(N);
    rep(i, N) A[i] = i+1, B[i] = N - i;

    rep(i, N) {
        int index = p[i];
        for (int j = index; j < N; ++j)  A[j] += i;
        for (int j = 0; j <= index; ++j) B[j] += i;
    }

    for (auto &i : A) cout << i << " ";
    cout << endl;
    for (auto &i : B) cout << i << " ";
    cout << endl;
}