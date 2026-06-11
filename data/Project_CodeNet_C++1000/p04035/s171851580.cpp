#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <queue>
#include <iomanip>
#include <iterator>

#define MOD 1000000007
#define INF 1000000001

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


template <class T>
ostream &operator<<(ostream &o, const vector<T>&obj) {
    o << "["; for (int i = 0; i < (int)obj.size(); ++i) o << (i > 0 ? ", " : "") << obj[i]; o << "]"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const pair<T, U>&obj) {
    o << "(" << obj.first << ", " << obj.second << ")"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const map<T, U>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const set<T>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const queue<T>&obj) {
    queue<T> obj_cp = obj;
    bool first = true;
    o << "{";
    while (!obj_cp.empty()) { o << (!first ? ", " : "") << obj_cp.front(); obj_cp.pop(); first = false; }
    o << "}"; return o;
}

void print() {
    cout << "\n";
}
template<class Head, class... Body>
void print(Head head, Body... body) {
    cout << head << " ";
    print(body...);
}


int main(int argc, char const *argv[]) {
    int N, L;
    cin >> N >> L;

    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    ll pair_len_max = 0;
    int pair_idx;
    for (int i = 0; i < N-1; ++i) {
        ll pair_len = a[i] + a[i+1];
        if (pair_len > pair_len_max) {
            pair_len_max = pair_len;
            pair_idx = i;
        }
    }
    // print("pair_idx =", pair_idx);

    if (pair_len_max < L) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        for (int i = 0; i < pair_idx; ++i) {
            cout << i+1 << endl;
        }
        for (int i = N-2; i > pair_idx; --i) {
            cout << i+1 << endl;
        }
        cout << pair_idx + 1 << endl;
    }

    return 0;
}
