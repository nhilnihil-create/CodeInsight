#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,u=1;
  cin >> h >> w;
  string s[h][w];
  char t='A';
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> s[i][j];
      if(s[i][j]=="snuke"){
        cout << t << u << endl;
        return 0;
      }
      t++;
    }
    u++;
    t='A';
  }
}
