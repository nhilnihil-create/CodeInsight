#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)

int main()
{
    int N; cin >>N;
    unordered_set<int> s;
    rep(i, N) {
        int A; cin >> A;
        s.insert(A);
    }
    int uniq = s.size();
    int dup = N-uniq;

    cout << uniq-(dup%2) << endl;
}
