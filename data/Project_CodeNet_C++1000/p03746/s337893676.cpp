#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
#define EPS (1e-7)
#define INF (1e9 + 10)
#define PI (acos(-1))
#define MOD (1000000007)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define ALL(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int N,M;
    cin >> N;cin >> M;
    vector<vector<int>> G;
    G.assign(N, vector<int>());
    REP(i, M) {
        int x, y;
        cin >> x;cin >> y;
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }
    deque<int> ans;
    int first = -1;
    REP(i, N) {
        if (G[i].size() >= 2) {
            first = i;
            break;
        }
    }
    if (first == -1) {
        cout << "2" << endl << "1 2" << endl;
        return 0;
    }
    int start = G[first][0];
    int end = G[first][1];
    for (int i: G[first]){
        G[i].erase( find(ALL(G[i]), first) );
    }
    ans.push_back(first);
    while (true){
        ans.push_back(end);
        if (!G[end].empty()){
            for (int i: G[end]){
                G[i].erase( find(ALL(G[i]), end) );
            }
            if (G[end][0] == start && G[end].size() == 1){
                break;
            } else if(G[end][0] == start) {
                end = G[end][1];
            } else {
                end = G[end][0];
            }
        } else break;
    }
    while (true){
        ans.push_front(start);
        if (!G[start].empty()){
            for (int i: G[start]){
                G[i].erase( find(ALL(G[i]), start) );
            }
            start = G[start][0];
        } else break;
    }
    cout << ans.size() << endl;
    for (int i :ans){
        cout << i+1 << " ";
    }
    cout << endl;
}