#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  vector<int> Alice(101,2);
  vector<int> Bob(101,0);
  for (int i=a ; i<b; i++){
    Alice[i]=1;
  }
  for (int i=c; i<d; i++){
    Bob[i]=1;
  }
  int ans = 0;
  for(int j=0; j<101; j++){
    if(Alice[j]==Bob[j]) ans+=1;
  }
  cout << ans << endl;
}