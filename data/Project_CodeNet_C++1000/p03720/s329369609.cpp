#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        w[a-1]++;
        w[b-1]++;
    }
    rep(i, n) {
        cout << w[i] << endl;
    }

    return 0;
}