#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

#define INF 1e9
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(m);
    vector<int> d(m);
    rep(i, n) {
        cin >> a.at(i) >> b.at(i);
    }
    rep(i, m) {
        cin >> c.at(i) >> d.at(i);
    }
    int dis;
    vector<int> diss(n, INF);
    vector<int> ans(n);
    rep(i, n) {
        rep(j, m) {
            dis = abs(a.at(i) - c.at(j)) + abs(b.at(i) - d.at(j));
            if (dis < diss.at(i)) {
                diss.at(i) = dis;
                ans.at(i) = j + 1;
            }
        }
    }
    rep(i, n) {
        cout << ans.at(i) << endl;
    }
}