#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string.h>
#include <stack>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int h,w;
    cin >> h >> w;
    vector<string>mp(h);
    rep(i, 0, h) {
        cin >> mp[i];
    }
    rep(i, 0, h) {
        cout << mp[i] << endl;
        cout << mp[i] << endl;
    }
    return 0;
}
