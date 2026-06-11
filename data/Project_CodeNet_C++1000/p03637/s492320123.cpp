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
// typedef unsigned long long ull;
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
    int N;
    cin >> N;

    vector<int> x4, x2, x1;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 4 == 0) {
            x4.push_back(a);
        } else if (a % 2 == 0) {
            x2.push_back(a);
        } else {
            x1.push_back(a);
        }
    }

    int i4 = 0, i2 = 0, i1 = 0;
    int state = 4;
    vector<int> a_sorted;
    while (true) {
        // print("state =", state);
        if (state == 4 && i1 < x1.size()) {
            a_sorted.push_back(x1[i1]);
            state = 1;
            i1 += 1;
        } else if ((state == 2 || state == 4) && i2 < x2.size()) {
            a_sorted.push_back(x2[i2]);
            state = 2;
            i2 += 1;
        } else if (i4 < x4.size()) {
            a_sorted.push_back(x4[i4]);
            state = 4;
            i4 += 1;
        } else {
            break;
        }
    }
    // print(a_sorted);
    if (a_sorted.size() == N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
