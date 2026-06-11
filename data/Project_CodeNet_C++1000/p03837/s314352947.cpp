#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
const int MAX = 1000;
const int INF = 1e9;

int main(){
    int a, b, c, ans;
    int n, m, d[MAX][MAX];
    vector<int> A,B,C;
    cin >> n;
    cin >> m;
    fill((int*)d, (int*)(d + n), 0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) if (i != j) d[i][j] = INF;
    }
    for (int i = 0; i < m; i++){
        cin >> a;
        cin >> b;
        cin >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
    }
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
    int res = 0;
    bool shortest;
    for (int i = 0; i < m; i++){
        shortest = false;
        for (int j = 0; j < n; j++){
            if (d[j][A[i]] + C[i] == d[j][B[i]]) shortest = true;
        }
        if (shortest) res += 1;
    }
    cout << m - res << endl;
    return 0;
}