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
    string s;
    cin >> s;
    ll ans = 0;
    rep(i, 0, s.size()){
        if(s[i] == 'W' && s[i+1] == 'B')ans++;
    }
    reverse(s.begin(), s.end());
    rep(i, 0, s.size()){
        if(s[i] == 'W' && s[i+1] == 'B')ans++;
    }
    cout << ans << endl;
   return 0;
}