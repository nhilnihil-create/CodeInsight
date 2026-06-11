#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n,m;
  cin >> n >> m;
  
  vector<vector<int>> stu(n,vector<int>(2)),che(m,vector<int>(2));
  for ( int i = 0; i < n; i++){
    for ( int j = 0; j < 2; j++){
      cin >> stu[i][j];
    }
  }
  for ( int i = 0; i < m; i++){
    for ( int j = 0; j < 2; j++){
      cin >> che[i][j];
    }
  }
  
  long long kyori,mn;
  int pnt;
  
  for ( int i = 0; i < n; i++){
    kyori = 0;
    mn = 10000000000;
    for ( int j = 0; j < m; j++){
      kyori = abs(stu[i][0] - che[j][0]) + abs(stu[i][1] - che[j][1]);
      if ( mn > kyori ){
        mn = kyori;
        pnt = j+1;
      }
    }
    cout << pnt << endl;
  }
   
}