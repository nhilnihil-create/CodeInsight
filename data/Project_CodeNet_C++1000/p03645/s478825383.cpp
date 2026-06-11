#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,m,i;
  cin >> n >> m;
  vector<int> a(m),b(m),x(n,0);
  for(i=0;i<m;i++){
    cin >> a.at(i) >> b.at(i);
    if(a.at(i)==1){
      x.at(b.at(i))++;
    }
    if(b.at(i)==n){
      x.at(a.at(i))++;
    }
  }
  for(i=2;i<=n-1;i++){
    if(x.at(i)==2){
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}