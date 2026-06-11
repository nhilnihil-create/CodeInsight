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

/*!* [binsearch] *!*/
/*+* 二分探索 *+*/
// judge を満たすような(l,r]内の下限を求める
// l:[X] 定義域の下端
// r:[X] 定義域の上端
// judge:[F = X -> bool] 値 X を評価する関数
// lower:[bool] false にすると代わりに[l,r)内の上限を求める
// eps:[X] 終了距離

template <typename X, typename F>
X BinSearch(X l, X r, F judge, bool lower = true, X eps = 1) {
    while (r - l > eps) {
        X m = (r + l) / 2;
        if (judge(m) == lower) {
            r = m;
        } else {
            l = m;
        }
    }
    return lower ? r : l;
}

int med(int a, int b, int c) {
    vector<int> v{a, b, c};
    sort(WHOLE(v));
    return v[1];
}

void experiment(vector<int> &a) {
    int N = (a.size() + 1) / 2;
    string delim = "";
    for(int i = 0; i < 2 * N - 1; i++) {
        cout << delim << a[i];
        delim = " ";
    }
    cout << endl;
    for(int i = 1; i < N; i++) {
        cout << string(2 * i, ' ');
        delim = "";
        for(int j = 0; j < 2 * (N - i) - 1; j++) {
            a[j] = med(a[j], a[j + 1], a[j + 2]);
            cout << delim << a[j];
            delim = " ";
        }
        cout << endl;
    }
}

int main() {
    int N, M;
    cin >> N;
    M = 2 * N;
    vector<int> A(M - 1);
    for(int &a : A) cin >> a;
    int ans = BinSearch(0, M - 1, [&](int k) -> bool {
        // ans <= k かどうか
        int j = M, a = -1;
        // 最も近い (1,1) か (0,0) を探す
        for(int d : {-1, 1}) {
            for(int i = 0; i < N - 1; i++) {
                int x = A[N - 1 + d * i] <= k;
                int y = A[N - 1 + d * (i + 1)] <= k;
                if(x == y) {
                    if(i < j) {
                        a = x;
                        j = i;
                    }
                    break;
                }
            }
        }
        if(j == M) a = A[0] <= k;
        return a;
    });
    cout << ans << endl;
    return 0;
}