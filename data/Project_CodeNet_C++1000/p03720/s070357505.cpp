#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <iostream>
#include <set>
 
int main(void){
  int n,m;cin >> n >> m;
  vector<int> RoadSum(n,0);
  for(int i=0;i<m;i++){
    int a,b;cin >> a >> b;
    RoadSum[a-1]++;
    RoadSum[b-1]++;
  }
  for(int i=0;i<n;i++){
    cout << RoadSum[i] << endl;
  }
}