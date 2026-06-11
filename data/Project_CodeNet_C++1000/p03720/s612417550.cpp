#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n,m;
  const int NMMAX = 50;
  cin >> n >> m;
  int a[NMMAX],b[NMMAX];
  for(int i=0;i<m;i++){
    cin >> a[i] >> b[i];
  }
  int count[NMMAX];
  for(int i=0;i<NMMAX;i++){
    count[i] = 0;
  }
  for(int i=0;i<m;i++){
    count[a[i]-1]++;
    count[b[i]-1]++;
  }
  for(int i=0;i<n;i++){
    cout << count[i] << endl;
  }
  return 0;
}