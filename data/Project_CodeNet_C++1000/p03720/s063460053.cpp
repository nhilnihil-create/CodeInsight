#include<bits/stdc++.h>
using namespace std;

int main (void){
  int a,b,n,m;
  int road[55] = {};
  cin >> n >> m;

  for(int i = 0;i < m;i++){
    cin >> a >> b;
    a--;
    b--;
    road[a]++;
    road[b]++;
  }

  for(int i = 0;i < n;i++){
    cout << road[i] << '\n';
  }
  return 0;
}
