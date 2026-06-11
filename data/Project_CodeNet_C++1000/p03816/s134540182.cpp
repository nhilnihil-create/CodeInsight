#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    set<int> s;
    for (int i = 0; i < N; i++) s.insert(A[i]);
    if (s.size()%2) cout << s.size() << endl;
    else cout << s.size() - 1 << endl;
}
