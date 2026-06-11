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
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int a[216000];
Int n;
Int b[216000];
Int check(Int val){
  int mid = n -1;
  for(int i = 0;i < 2*n-1;i++)b[i] = a[i] > val;
  for(int k = 0;k < n-1;k++){
    if(b[mid + k] == b[mid+k+1])return b[mid+k];
    if(b[mid-k] == b[mid-k-1])return b[mid-k];
  }
  return (b[mid] + n + 1) % 2;
}

int main(){
  cin >> n;
  for(int i = 0;i < 2*n-1;i++)cin >> a[i];
  int bottom = 1, top = 2*n-1;
  while(top - bottom > 1){
    int mid = (top + bottom) / 2;
    if(check(mid) == 1)bottom = mid;
    else top = mid;
  }
  cout << top << endl;  
  return 0;
}