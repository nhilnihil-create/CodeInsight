#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

bool match(int off_i, int off_j, vector<string>& A, vector<string>& B) {
//    int N = A[0].size();
    int M = B[0].size();
    rep(i, M) {
        rep(j, M) {
            if(A[off_i+i][off_j+j] != B[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A;
    string tmp;
    rep(i, N) {
        cin >> tmp;
        A.push_back(tmp);
    }

    vector<string> B;
    rep(i, M) {
        cin >> tmp;
        B.push_back(tmp);
    }

    int cnt = N - M + 1;
    rep(i, cnt) {
        rep(j, cnt) {
            if(match(i, j, A, B)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

