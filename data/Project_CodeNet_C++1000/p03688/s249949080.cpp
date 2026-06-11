#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) {
        cin >> a;
    }
    int max_a = *max_element(all(A));
    int min_a = *min_element(all(A));
    if (max_a - min_a >= 2) {
        cout << "No" << endl;
        return 0;
    }
    if (max_a == min_a) {
        if (N == A[0] + 1 || 2 * A[0] <= N) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        int max_cnt = 0;
        int min_cnt = 0;
        for (auto& a : A) {
            if (a == max_a) {
                ++max_cnt;
            }
            else {
                ++min_cnt;
            }
        }
        int rest_cnt = max_a - min_cnt;
        if (rest_cnt > 0 && rest_cnt * 2 <= max_cnt) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}