#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector< vector<int> > A(N, vector<int>(0));
    for(int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }

    vector<bool> P(N, false);
    P[0] = P[A[0][0]] = true;
    deque<int> path(2);
    path[0] = 0;
    path[1] = A[0][0];
    while(true) {
        bool flag = true;
        for(int to : A[path[0]]) {
            if(!P[to]) {
                path.push_front(to);
                P[to] = true;
                flag = false;
                break;
            }
        }
        for(int to : A[path[path.size() - 1]]) {
            if(!P[to]) {
                path.push_back(to);
                P[to] = true;
                flag = false;
                break;
            }
        }
        if(flag) break;
    }

    cout << path.size() << endl;
    for(int v : path) cout << v + 1 << ' ';
    cout << endl;
}