#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-11;

int bo[200010][27];

struct edge {
    int to, cost;
    //char alph;
};

int V;
vector<edge> G[200010];
ll d[200010];
//string str[200010];
ll back[200010];

void addedge(int st, int ed, int co) {
    edge e;
    e.to = ed;
    e.cost = co;
    G[st].push_back(e);
}

void BFS(int n) {
    fill(d, d + V, llmax);
    queue<int> que;
    d[n] = 0;
    back[n] = -1;
    //str[n] = "";
    que.push(n);
    while (que.size() > 0) {
        int base = que.front();
        que.pop();
        int s = G[base].size();
        for (int i = 0; i < s; i++) {
            int to = G[base][i].to;
            //char c = G[base][i].alph;
            if (d[to] == llmax) {
                d[to] = d[base] + 1;
                back[to] = base;
                //str[to] = str[base] + c;
                que.push(to);
            }//  else if (d[to] == d[base] + 1) {
            //     if (str[base] + c < str[to]) {
            //         str[to] = str[base] + c;
            //     }
            // }
        }
    }
}

int main() {
    string A;
    cin >> A;
    int len = A.size();
    fill(bo[len], bo[len] + 27, -1);
    // bo[len][26] = 0;
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            bo[i][j] = bo[i + 1][j];
        }
        char c = A[i];
        bo[i][c - 'a'] = i + 1;
        // if (bo[i + 1][26] != 100) {
        //     int num = -1;
        //     for (int j = 0; j < 26; j++) {
        //         if (bo[i][j] == -1) {
        //             num = j;
        //         }
        //     }
        //     if (num != -1) {
        //         bo[i][26] = num;
        //     } else {
        //         bo[i][26] = 100;
        //     }
        // } else {
        //     bo[i][26] = 100;
        // }
    }
    V = len + 2;
    // for (int i = 0; i < len + 1; i++) {
    //     for (int j = 0; j < 26; j++) {
    //         cout << bo[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < len + 1; i++) {
        for (int j = 0; j < 26; j++) {
            if (bo[i][j] == -1) {
                addedge(i, V - 1, 1);
            } else {
                addedge(i, bo[i][j], 1);
            }
        }
    }
    BFS(0);
    //string ans = str[V - 1];
    // for (int i = 0; i < len + 2; i++) {
    //     cout << str[i] << endl;
    // }
    string ans = "";
    int num = V - 1;
    while (back[num] != -1) {
        int ba = back[num];
        for (int i = 0; i < 26; i++) {
            bool ok = false;
            if (num == V - 1 && bo[ba][i] == -1) {
                ok = true;
            }
            if (num != V - 1 && bo[ba][i] == num) {
                ok = true;
            }
            if (ok) {
                char c = i + 'a';
                ans = c + ans;
                break;
            }
        }
        num = ba;
    }
    cout << ans << endl;
}
