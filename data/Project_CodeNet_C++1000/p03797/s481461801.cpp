#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#include <iomanip>
#include <utility>
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n) for(int i=1;i<=(n);i++)
#define lol long long
#define SUM(n) ((n)+1)*(n)/2
#define mp make_pair
#define fi first
#define se second
#define pu push_back
#define SYOU(x) setprecision(x+1)
#define abs(x,y) (max(x,y)-min(x,y))
#define all(v) v.begin(),v.end()
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD=int(1e9)+7; 
using namespace std;
using pii = pair<int,int>;
  
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    lol n, m, sum = 0;
    cin >> n >> m;
    m /= 2;
    sum += min(n,m);
    m -= n;
    // cout << n << m;
    if( m >= 2 ){
      sum += m/2;
    }
    cout << sum << '\n';
    return 0;
}
