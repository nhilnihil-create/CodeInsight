#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  vector<string> v(H);
  for (int i = 0; i < v.size(); i++)
  	cin >> v.at(i);

  
  for (int i = 0; i < H+2; i++){
       if(i == 0 || i == H+1){
         for (int j = 0; j < W+2; j++)
          cout << "#";
       }else {
          cout << "#" <<v.at(i-1)<< "#" ;
       }
       cout << endl;
     }
  
}