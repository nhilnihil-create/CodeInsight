#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N, M, A, B, start, goal;
    cin >> N >> M;
    vector<vector<int>> edge(N, vector<int>(0));
    vector<int> X(0), Y(0);
    vector<bool> done(N, false);
    rep(i, M) {
        cin >> A >> B;
        A--;
        B--;
        edge[A].push_back(B);
        edge[B].push_back(A);
        if (i == 0) {
            X.push_back(A);
            done[A] = true;
            start = A;
            Y.push_back(B);
            done[B] = true;
            goal = B;
        }
    }
    bool f = true;
    while (f) {
        f = false;
        rep(i, edge[start].size()) {
            int j = edge[start][i];
            if (done[j]) continue;
            start = j;
            done[j] = true;
            X.push_back(j);
            f = true;
            break;
        }
    }
    f = true;
    while (f) {
        f = false;
        rep(i, edge[goal].size()) {
            //cout << "i=" << i << " ";
            int j = edge[goal][i];
            if (done[j]) continue;
            goal = j;
            done[j] = true;
            Y.push_back(j);
            f = true;
            //cout << j << endl;
            break;
        }
    }
    cout << X.size() + Y.size() << endl;
    rep(i, X.size()) {
        cout << X[X.size() - 1 - i]  + 1 << " ";
    }
    rep(i, Y.size()) {
        cout << Y[i] + 1;
        if (i == Y.size() - 1) cout << endl;
        else cout << " ";
    }
    /*
    rep(i, N) {
        cout << i << " ";
        rep(j, edge[i].size()) {
            cout << edge[i][j] << " ";
        }
        cout << endl;
    }
    */
}