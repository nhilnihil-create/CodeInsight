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
    int a,b;
    cin >> a >> b;
    ll ans = b;
    rep(i, 0, a-1){
        ans *= b-1;
    }
    cout << ans << endl;
    return 0;
}

