#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    int x = 0;
    int n;
    string s;
    cin >> n >> s;
    int ans = x, ans1 = x;
    rep(i, n) {
        if(s[i] == 'I') {
            ans1++;
        }
        else ans1--;
        ans = max(ans, ans1);
    }

    cout << ans << endl;

    return 0;
}