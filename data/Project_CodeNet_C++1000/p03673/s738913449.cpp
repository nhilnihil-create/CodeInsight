#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N;
    cin >> N;
    vector<int64_t>vec(N);
    for (int64_t i=0; i<N; i++) {
        cin >> vec.at(i);
    }

    reverse(vec.begin(), vec.end());
    vector<int64_t>ans(N);
    int64_t count = 0;
    for (int i=0; i<N; i++) {
        if (i % 2 == 0) {
            ans[i-count] = vec[i];
        } else {
            ans[N-1 - count] = vec[i];
            count += 1;
        }
    }

    for (int64_t i=0; i<N; i++) {
        cout << ans[i];
        if (i < N-1)  {
            cout << " ";
        }
    }

    cout << endl;
    return 0;
}