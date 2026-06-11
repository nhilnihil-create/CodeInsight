#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <climits>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <queue>
#define ll long long
#define REP(a,b) for(ll a=0; a<b; a++)
using namespace std;

vector <int> base;
vector <bool> tempbase;

int main() {
  int N;
  cin >> N;
  REP(i, 2*N-1){
    int temp;
    cin >> temp;
    base.push_back(temp);
  }
  int l = 1;
  int r = 2*N-1;
  int ans = 0;
  while(l <= r){
    int mid = (l+r)/2;
    REP(i, base.size()){
      tempbase.push_back(base[i] >= mid);
    }
    int flag = -1;
    REP(i, N-1){
      if(tempbase[N-1+i] == tempbase[N+i]){
        flag = tempbase[N+i];
        break;
      }
      if(tempbase[N-1-i] == tempbase[N-2-i]){
        flag = tempbase[N-1-i];
        break;
      }
    }
    if(flag == -1) flag = tempbase[0];
    if(flag == 1){
      ans = max(ans, mid);
      l = mid+1;
    }else r = mid-1;
    tempbase.clear();
  }
  cout << ans << endl;
}