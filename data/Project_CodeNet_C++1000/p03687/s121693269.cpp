#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<list>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n;i++)
#define ALL(a)  (a).begin(),(a).end()
const int MOD = 1000000007;
int n, m, c, k,sum = MOD;
int main() {
    string s; cin >> s;
    for (char a = 'a';a <= 'z';a++) {
        k = 0; c = 0;
        for (auto it : s) {
            if (it == a) k = 0;
            else c = max(c, ++k); // ++k != k++
        }
        sum = min(sum, c);
    }
    cout << sum << endl;
}