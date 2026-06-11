#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<long long>> a(n, vector<long long>(2));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> a.at(i).at(j);
    }
  }
  vector<vector<long long>> b(m, vector<long long>(2));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> b.at(i).at(j);
    }
  }
  vector<vector<long long>> min(n, vector<long long>(2));
  for(int i=0;i<n;i++){
  	min.at(i).at(0)=pow(10,16);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(min.at(i).at(0)>abs((a.at(i).at(0))-b.at(j).at(0))+abs(a.at(i).at(1)-b.at(j).at(1))){
        min.at(i).at(0) =abs(a.at(i).at(0)-b.at(j).at(0))+abs(a.at(i).at(1)-b.at(j).at(1));
        min.at(i).at(1)=j+1;
       }
    }
  }
  for(int i=0;i<n;i++){
  	cout << min.at(i).at(1) << endl;
  }
}


