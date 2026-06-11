#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i = 0; i < n; i++)
const int INF = 1001001001;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> data;
    rep(i, n) {
        data[s[i]]++;
    }
    string ans = "Yes";
    //E,Wのどちらか一方が0である条件
    if (data['E'] + data['W'] != 0 && data['E'] * data['W'] == 0) {
        ans = "No";
    }
    if (data['N'] + data['S'] != 0 && data['N'] * data['S'] == 0) {
        ans = "No";
    }
    cout << ans << endl;
 	return 0;
}