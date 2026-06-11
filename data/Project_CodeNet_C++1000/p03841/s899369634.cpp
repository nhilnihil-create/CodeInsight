#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vector2d = vector<vector<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
int main() {
    int N;
    cin >> N;
    vector<int> A(N * N, -1);
    vector<pair<int, int>> X;
    vector<bool> complete(N, false);
    for (int n = 1; n <= N; n++) {
        int x;
        cin >> x;
        x--;
        X.push_back({x, n});
        A[x] = n;
    }
    sort(WHOLE(X));

    int j = 0;
    for(int i = 0; i < N; i++) {
        int x, n;
        tie(x, n) = X[i];
        for(int k = n; k > 1; j++) {
            if(A[j] < 0) {
                A[j] = n;
                k--;
            } else if(j == x) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    j = 0;
    for(int i = 0; i < N; i++) {
        int x, n;
        tie(x, n) = X[i];
        for(int k = N + 1 - n; k > 1; j++) {
            if(A[j] < 0) {
                if(x < j) {
                    A[j] = n;
                    k--;
                } else {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;

    string delim = "";
    for(auto a : A) {
        cout << delim << a;
        delim = " ";
    }
    return 0;
}