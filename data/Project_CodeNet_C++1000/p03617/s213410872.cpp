#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    ll Q,H,S,D,N;
    cin >>  Q  >> H >> S >> D >>  N;
    H = min(H,2*Q);
    S = min(S,2*H);
    ll ans;
    if(D > S*2){
        ans = N * S;
    }
    else{
        ans = (N/2)*D + (N%2)*S;
    }
    cout << ans << endl;
}