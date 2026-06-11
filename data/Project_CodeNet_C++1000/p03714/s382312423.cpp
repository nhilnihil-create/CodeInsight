#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <tuple>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>

#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long>vll;
typedef pair<int,int> pi;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

int main(){
  int n;
  cin >> n;
  vector<int> a(n*3);
  for(int i = 0; i < n * 3; i++){
    cin >> a[i];
  }

  priority_queue<int, vector<int>, greater<int> > pq;
  vector<ll> front(n + 1, 0);
  ll sum = 0;
  for(int i = 0; i < n; i++){
    sum += a[i];
    pq.push(a[i]);
  }
  front[0] = sum;
  int index = 1;
  for(int i = n; i < n * 2; i++){
    pq.push(a[i]);
    int p = pq.top();pq.pop();
    sum = sum + a[i] - p;
    front[index++] = sum;
  }

  priority_queue<int> pq2;
  vector<ll> back(n + 1, 0);
  sum = 0;
  for(int i = n * 3 - 1; i >=  n * 2; i--){
    sum += a[i];
    pq2.push(a[i]);
  }
  back[0] = sum;
  index = 1;
  for(int i = n * 2 - 1; i >= n; i--){
    pq2.push(a[i]);
    int p = pq2.top();pq2.pop();
    sum = sum + a[i] - p;
    // for(auto x : back)cout << x << " ";cout << endl;
    back[index++] = sum;
  }

  ll ans = LLONG_MIN;
  for(int i = 0; i < n + 1; i++){
    ans = max(ans, front[i] - back[n - i]);
  }
  cout << ans << endl;
  return 0;
}
