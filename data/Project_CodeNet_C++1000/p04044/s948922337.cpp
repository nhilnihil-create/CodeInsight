#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int n,l;
    cin >> n >> l;
    vector<string>s(n);
    rep(i, 0, n){
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    string ans = "";
    rep(i, 0, n){
        ans += s[i];
    }
    cout << ans << endl;
}
