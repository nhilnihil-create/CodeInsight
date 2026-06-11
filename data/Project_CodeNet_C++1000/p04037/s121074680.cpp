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
    vector<int> A(N);
    for(int &a : A) cin >> a;
    sort(REV_WHOLE(A));
    int p;
    for(int i = 0; i <= N; i++) {
        if(i + 1 <= A[i]) {
            p = i;
        } else break;
    }
    bool ans;
    ans = (A[p] - p + 1) % 2 == 1;
    int x = 0;
    for(int i = p + 1; i < N && A[i] == p + 1; i++, x++);
    ans |= x % 2 == 1;
    cout << (ans ? "First" : "Second") << endl;
    return 0;
}