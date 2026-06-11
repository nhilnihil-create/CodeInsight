#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,tmp1,tmp2;
  cin >> n >> m;
  vector<int> town(n);
  for(int i=0;i<m;i++){
    cin >> tmp1 >> tmp2;
    town.at(tmp1-1)++;
    town.at(tmp2-1)++;
  }
  for(int i=0;i<n;i++){
    cout << town.at(i) << endl;
  }
}