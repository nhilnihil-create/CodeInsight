#include <iostream>
#include <functional>

struct Closed_Section {
    bool valid;
    int64_t begin;
    int64_t end;
    Closed_Section(bool _valid, int64_t _begin, int64_t _end) {
        valid = _valid; begin = _begin; end = _end;
    }
    Closed_Section() {
        valid = false, begin = 0; end = -1; //配列を定義するためにデフォルトコンストラクタが必要。
    }
    int64_t size() { return valid ? end - begin + 1 : 0; }
    Closed_Section operator*(const Closed_Section &r) const {
        if (!valid) { return Closed_Section(valid, begin, end); }
        if (!r.valid) { return r; }
        if (end < r.begin) { return Closed_Section(false, 0, -1); }
        if (r.end < begin) { return Closed_Section(false, 0, -1); }
        return Closed_Section(true, std::max(begin, r.begin), std::min(end, r.end));
    }
    void dump() { std::cout << "valid:" << valid << " begin:" << begin << " end:" << end << std::endl; }
};

// end of template

int64_t N;

const int64_t MAX_N = 1e5 + 10;
const int64_t MOD = 1e9 + 7;

int64_t T[MAX_N] = {};
int64_t A[MAX_N] = {};
Closed_Section Ts[MAX_N];
Closed_Section As[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> T[i];
    }
    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        if (T[i-1] < T[i]) {
            Ts[i] = Closed_Section(true, T[i], T[i]);
        } else {
            Ts[i] = Closed_Section(true, 1, T[i]);
        }
    }
    for (int i = N; 1 <= i; i--) {
        if (A[i+1] < A[i]) {
            As[i] = Closed_Section(true, A[i], A[i]);
        } else {
            As[i] = Closed_Section(true, 1, A[i]);
        }
    }

    int64_t ret = 1;
    for (int i = 1; i <= N; i++) {
        ret *= (Ts[i]*As[i]).size();
        ret %= MOD;
    }
    std::cout << ret << std::endl;
}