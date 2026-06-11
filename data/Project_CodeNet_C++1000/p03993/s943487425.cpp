#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1000000000;


bool is_in(int x, vector<int>nodes){
    for (int i=0; i<nodes.size(); i++){
        if (nodes[i] == x)return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<int>a(N);
    vector<vector<int>>graph(N);
    for (int i=0; i<N; i++)cin >> a[i];
    for (int i=0; i<N; i++){
        int ai = a[i];
        ai--;
        graph[i].push_back(ai);
    }

    int cnt = 0;
    for (int i=0; i<N; i++){
        // graph[i][j] in graph[graph[i][j]] -> cnt++
        vector<int>nodes = graph[i];
        for (int j=0; j<nodes.size(); j++){
            if (is_in(i, graph[nodes[j]]))cnt++;
        }
    }
    cout << cnt/2 << endl;

}