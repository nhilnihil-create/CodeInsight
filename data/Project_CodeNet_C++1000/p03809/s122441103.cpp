#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}};
ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}
int main() {
    int N;
    cin >> N;
    vector<i64> A(N);
    for(i64 &x : A) cin >> x;
    vector2d<int> edge(N);
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int r = -1; // root
    for(r = 0; r < N; r++) {
        if(edge[r].size() == 1) {
            break;
        }
    }
    bool ans = true;
    ans &= recursive([&](auto f, int prev, int i) -> i64 {
        if(i != r && edge[i].size() == 1) return A[i];
        i64 n;
        if(i == r) n = A[i];
        else n = 2 * A[i];
        for(int j : edge[i]) {
            if(j == prev) continue;
            i64 x = f(f, i, j);
            if(x > A[i]) ans = false;
            n -= x;
        }
        if(n > A[i] || 0 > n) ans = false;
        return n;
    })(r, r) == 0;
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}

