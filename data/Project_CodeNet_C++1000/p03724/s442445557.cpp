#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
  int n,m;
  cin >> n >> m;

  map<int,int> cnt;

  for(int i = 0;i < m;i++){
    int a,b;
    cin >> a >> b;
    cnt[a]++;
    cnt[b]++;
  } 

  bool flag = true;
  for(auto p:cnt){
    if(p.second % 2 == 1)flag = false;
  }

  if(flag)cout << "YES" << endl;
  else cout << "NO" << endl;
}