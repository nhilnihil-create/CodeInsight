#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))


Int pos[216000];
Int cnt[216000];
set<Int> nums;
Int res, n, a;
Int mx;

void ok(){
  cout << "Possible" << endl;
  exit(0);
}

void ng(){
  cout <<  "Impossible" << endl;
  exit(0);
}


int main(){
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> a;
    cnt[a]++;
    mx = max(mx, a);
  }
  int center = 0;
  while (cnt[center] == 0)center ++ ;

  if(center == 1){
    if(cnt[center] == 2 && n == 2)ok();
    if(cnt[2] == n-1)ok();
    ng();
  }
  
  if(cnt[center] == 1){
    for(int i = center+1;i <= center*2;i++){
      if(cnt[i]==0)ng();
    }
    if(mx <= center * 2)ok();
    else ng();
  }

  
  if(cnt[center] == 2){
    for(int i = center+1;i <= center*2-1;i++){
      if(cnt[i]==0)ng();
    }
    if(mx <= center * 2-1)ok();
    else ng();
  }
  
  ng();
  return 0;
}
