// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ull  unsigned long long
typedef string str;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int INF = 1e9 + 5;
const int N = 2e5 + 1;
// int a[N][N];

// int a[1][N], b[N][1];
int main(){
    speed;
    int n, m;
    cin >> n >> m;
    map<int, mii > v;
    int ok = 0;
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        v[x][y] = 1;
        if(x == 1 && v[y][n]){
            ok = 1;
        }
        if(y == n && v[1][x]){
            ok = 1;
        }
    }
    if(ok){
        cout << "POSSIBLE";
    }
    else{
        cout << "IMPOSSIBLE";
    }
}