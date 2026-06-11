#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N, W;
    cin >> N >> W;
    vector<string>masu(N);
    for (int i=0; i<N; i++) {
        cin >> masu.at(i);
    }

    for (int i=0; i<=N+1; i++) {
        for (int j=0; j<=W+1; j++) {
            if (i == 0 || i == N+1 || j==0 || j==W+1) {
                cout << '#';
            } else {
                cout << masu[i-1][j-1];
            }
        }
        cout << endl;
    }
    return 0;
}