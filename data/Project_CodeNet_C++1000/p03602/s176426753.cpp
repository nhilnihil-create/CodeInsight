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
#include <unordered_set>
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
#include <random>
#include <cstring>


#define rep(i,n) for(int i=0;i<int(n);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back

using namespace std;
using ll = long long;

const ll mod = 1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

int N;
ll A[305][305];
bool graph[305][305];

void init(){
  for(int i = 0; i < 305; i++){
    for(int j = 0; j < 305; j++){
      A[i][j] = LLONG_MAX / 100;
      graph[i][j] = true;
    }
  }
}

int main(){
  init();
  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> A[i][j];
    }
  }

  bool ok = true;
  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
	if(i == j || j == k || k == i) continue;
	if(A[i][j] == A[i][k] + A[k][j]){
	  graph[i][j] = 0;
	}else if(A[i][j] > A[i][k] + A[k][j]){
	  ok = false;
	}
      }
    }
  }

  ll ans = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(graph[i][j]) ans += A[i][j];
    }
  }

  if(ok) cout << ans / 2 << endl;
  else cout << -1 << endl;
  return 0;
}
