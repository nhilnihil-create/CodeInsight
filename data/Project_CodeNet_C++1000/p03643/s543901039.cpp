#include <iostream>
#include <vector>
#include <set>
#include <map>
// #include <cmath>
// #include <algorithm>
// #include <numeric>
// #include <string>
// #include <queue>
// #include <iomanip>
// #include <list>
// #include <cassert>

// #define MOD 1000000007
// #define INF 1000000001

using namespace std;
// typedef unsigned long long ull;
// typedef long long ll;


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
    cout << "ABC" << N / 100 << (N/10) % 10 << N % 10 << endl;
    return 0;
}
