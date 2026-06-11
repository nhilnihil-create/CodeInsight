#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n;
  vector<int> d(n);
  for(int i = 0; i < n; i++){
    cin >> d[i];
  }
  cin >> m;
  vector<pair<int,int>> e(m);
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    e[i].first = a;
    e[i].second = b;
  }
  for(int i = 0; i < m; i++){
    long long t = 0;
    for(int j = 0; j < n; j++){
      if(j+1 == e[i].first){
        t += e[i].second;
      }else{
        t += d[j];
      }
    }
    cout << t << endl;
  }
}