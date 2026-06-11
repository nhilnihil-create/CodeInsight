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

// #define MOD 1000000007
// #define INF 1000000001

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

void print() {
    cout << "\n";
}
template<class Head, class... Body>
void print(Head head, Body... body) {
    cout << head << " ";
    print(body...);
}

int main(int argc, char const *argv[]) {
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    vector<vector<int>> ans(H, vector<int>(W));
    int idx = 0;
    for (int i = 0; i < H*W; ++i) {
        int h = i / W;
        int w = (h % 2 == 0) ? i % W : W - 1 - i % W;
        // print(h, w, idx);
        ans[h][w] = idx + 1;

        a[idx] -= 1;
        if (a[idx] == 0) idx += 1;
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cout << ans[i][j] << (j < W-1 ? " " : "");
        }
        cout << endl;
    }

    return 0;
}
