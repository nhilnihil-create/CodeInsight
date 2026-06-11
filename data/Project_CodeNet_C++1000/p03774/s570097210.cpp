#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int64_t, int64_t>> students(N);
    vector<pair<int64_t, int64_t>> checks(M);
    for (int i=0; i<N; i++) {
        int64_t x, y;
        cin >> x >> y;
        students[i] = make_pair(x, y);
    }

    for (int i=0; i<M; i++) {
        int64_t x, y;
        cin >> x >> y;
        checks[i] = make_pair(x, y);
    }

    vector<int>idousaki(N);
    for (int i=0; i<N; i++) {
        int64_t min_kyori = INT64_MAX;
        int64_t idou_index = 0;
        pair<int64_t, int64_t> student = students[i];
        for (int j=0; j<M; j++) {
            pair<int64_t, int64_t> idousaki = checks[j];
            int64_t idoukyori = abs(student.first - idousaki.first) + abs(student.second - idousaki.second);
            if (idoukyori < min_kyori) {
                min_kyori = idoukyori;
                idou_index = j + 1;
            }
        }

        idousaki[i] = idou_index;
    }

    for (int i=0; i<N; i++) {
        cout << idousaki[i] << endl;
    }
    return 0;
}