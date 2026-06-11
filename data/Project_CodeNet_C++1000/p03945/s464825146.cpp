#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    s += (s[(int)s.size()-1] == 'B' ) ? 'W' : 'B';
    int n = s.length();
    vector<char> s_shrink;
    rep(i, n-1) {
        if ( s[i] != s[i+1] ) s_shrink.push_back(s[i]);
    }
    cout << int(s_shrink.size()-1) << endl;
    return 0;
}
