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
    int h, w;
    cin >> h >> w;
    vector<string> a(h); 
    rep(i, h) cin >> a[i];
    rep(i, w+2) cout << '#';
    cout << endl;
    rep(i, h) cout << '#' << a[i] << '#' << endl;
    rep(i, w+2) cout << '#';
    cout << endl;

    return 0;
}