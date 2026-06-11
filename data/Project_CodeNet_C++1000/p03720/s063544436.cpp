#include <bits/stdc++.h>
using namespace std;
char a [100][101] , b [102][102];
int main () {
  int n,m,c;
  cin>>n>>m;
  vector<int>a(2*m);
  for(int i=0;i<2*m;i++){
    cin>>a.at(i);
  }
  for(int i=1;i<=n;i++){
    c=0;
     for(int j=0;j<2*m;j++){
      if(i==a.at(j)){
        c++;
      }
     }
  cout<< c <<endl;
  }
}

	