// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
 
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <numeric>
#include <time.h>
#include <stack>
#include <bitset>

#define prev asasddlsa
#define rank aljds

#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i >= l; i++)
 
using namespace std;
 
typedef long long ll;
typedef double dbl;
 
template<typename T>
void print(const vector<T>& s){
    for (auto x : s)
        cout << x << " ";
    cout << endl;
}
 
template<class T>   
void print(const T* s, int n){
    for (int i = 0; i < n; i++)
        cout << s[i] << ' ';
    cout << endl;
}

template<class T>
void print(vector<vector<T>> s){
    for (int i = 0; i < s.size(); i++)
        print(s[i]);
}

const int maxn = 2001;

vector<int> s[maxn];
bitset<maxn> ok[maxn];

int dist[maxn];

void bfs(int v, int n){
    fill(dist, dist + n, n);
    dist[v] = 0;
    vector<int> q{v};
    int cur = 0;
    while (cur < q.size()){
        v = q[cur++];
        for (int u : s[v]){
            if (dist[u] > dist[v] + 1){
                q.push_back(u);
                dist[u] = dist[v] + 1;
            }
        }
    }
}

int solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        s[a - 1].push_back(b - 1);
        s[b - 1].push_back(a - 1);
    }
    int res = -1;
    for (int i = 0; i < n; i++){
        bfs(i, n);
        for (int j = 0; j < n; j++){
            if (dist[j] <= k)
                ok[i].set(j);
        }
        // print(dist, n);
        for (int j = 0; j < i; j++){
            if (dist[j] == k && j < i)
                res = max(res, (int)(ok[i] & ok[j]).count());
        }
    }
    if (res == -1)
        res = n;
    cout << n - res << endl;
    return 0;
}

int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);
    cout << fixed; 
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
