#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <regex>

#define rep(i, n) for(int i=0;i<(int)(n);i++)

using namespace std;

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int N;

int main() {
    cin >> N;
    printf("ABC%d\n", N);
}

