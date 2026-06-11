#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  string s;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin >> s;
      if(s == "snuke"){
        cout << (char)('A'+j-1) << i << endl;
      }
    }
  }
}