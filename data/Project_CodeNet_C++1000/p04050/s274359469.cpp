#ifndef __cplusplus
    cat << EOF
#endif
#include <bits/stdc++.h>
using namespace std;

#define rep(...) overload_rep(__VA_ARGS__, rep_1, rep_0)(__VA_ARGS__)
#define rep_0(i, end) for(int i = 0; i < (end); ++i)
#define rep_1(i, fr, ba) for(int i = (fr); i <= (ba); ++i)
#define overload_rep(arg0, arg1, arg2, name, ...) name
#define all(box) box.begin(), box.end()

template <class T, class U> inline bool chmax(T& lhs, const U& rhs) { if (lhs < rhs) { lhs = rhs; return 1; } return 0; }
template <class T, class U> inline bool chmin(T& lhs, const U& rhs) { if (lhs > rhs) { lhs = rhs; return 1; } return 0; }

int main() {

    int N, M;
    cin >> N >> M;

    if(M == 1) {
        cout << N << '\n';
        if(N >= 2) cout << "2\n" << N - 1 << " 1\n";
        else cout << "1\n1\n";
        return 0;
    }

    vector<int> A(M);
    vector<int> odd_place;
    rep(i, M) {
        cin >> A[i];
        if(A[i] % 2 == 1) odd_place.push_back(i);
    }

    if(odd_place.size() >= 3) {
        cout << "Impossible\n";
        return 0;
    }

    if(odd_place.size() >= 1) swap(A[0], A[odd_place[0]]);
    if(odd_place.size() >= 2) swap(A[M - 1], A[odd_place[1]]);
    vector<int> answer;
    if(A[0] > 1) answer.push_back(A[0] - 1);
    rep(i, M - 1) answer.push_back(A[i + 1]);
    ++answer.back();

    rep(i, M) {
        cout << A[i];
        cout << (i + 1 == M ? '\n' : ' ');
    }
    cout << answer.size() << '\n';
    rep(i, answer.size()) {
        cout << answer[i];
        cout << (i + 1 == answer.size() ? '\n' : ' ');
    }

}
